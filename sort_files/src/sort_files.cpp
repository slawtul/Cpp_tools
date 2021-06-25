#include "sort_files.h"

const std::unordered_map<std::string_view, std::string_view> sort_files::ext_to_dest{
    {".jpg",  "photos"},
    {".png",  "photos"},
    {".raw",  "photos"},
    {".arw",  "photos"},
    {".jpeg", "photos"},
    {".mp4",  "movies"},
    {".mov",  "movies"},
    {".mts",  "movies"},
    {".vob",  "movies"},
    {".avi",  "movies"}
};

const std::unordered_map<std::string_view, int> sort_files::month_to_quarter{
    {"January",   1},
    {"February",  1},
    {"March",     1},
    {"April",     2},
    {"May",       2},
    {"June",      2},
    {"July",      3},
    {"August",    3},
    {"September", 3},
    {"October",   4},
    {"November",  4},
    {"December",  4},
};

void sort_files::start()
{
    std::filesystem::create_directory(curr_path / "photos");
    std::filesystem::create_directory(curr_path / "movies");

    for (const auto f_exts = f_extensions(); const auto& file:std::filesystem::directory_iterator(curr_path)) {
        if (file.is_directory()) {
            continue;
        }

        const auto& f_path = file.path();
        auto f_ext = f_path.extension().string();
        if (f_ext.empty() || f_ext == ".") {
            continue;
        }

        std::transform(f_ext.begin(), f_ext.end(), f_ext.begin(), ::tolower);
        if (has_ext(f_ext, f_exts)) {
            const auto& [year, month] = year_and_month(file);
            const auto& quart = std::to_string(quarter_num(month));
            const auto& res_path = res_dest_path(dest_folder(f_ext), year, quart);
            f_print(f_path, year, month, quart);
            std::filesystem::create_directories(curr_path.assign(res_path));
            auto f_name = f_path.filename().string();
            std::transform(f_name.begin(), f_name.end(), f_name.begin(), ::tolower);
            std::filesystem::rename(f_path, res_path / f_name);
            ++f_counter;
        }
    }
}

int sort_files::count_f() const
{
    return f_counter;
}

void sort_files::f_print(const std::filesystem::path& f_path, const std::string_view& year, const std::string_view& month, const std::string_view& quarter)
{
    std::cout << f_path << "\t" << year << ", " << month << "\t" << "quarter: " << quarter << "\n";
}

int sort_files::quarter_num(const std::string_view& month)
{
    return month_to_quarter.find(month)->second;
}

bool sort_files::has_ext(const std::string_view& f_ext, const std::vector<std::string_view>& exts)
{
    return std::any_of(exts.begin(), exts.end(), [&](const auto& ext) { return ext == f_ext; });
}

std::vector<std::string_view> sort_files::f_extensions()
{
    std::vector<std::string_view> exts(ext_to_dest.size());
    for (const auto& entry:ext_to_dest) {
        exts.emplace_back(entry.first);
    }
    return exts;
}

std::string_view sort_files::dest_folder(const std::string_view& ext)
{
    return ext_to_dest.find(ext)->second;
}

std::filesystem::path sort_files::res_dest_path(const std::string_view& dest_folder, const std::string_view& year, const std::string_view& quarter)
{
    return curr_path.assign(dest_folder).append(year).append(quarter);
}

// It's 2020 and to get file modification date I need to write below lines!
// Good job C++ committers!
std::pair<std::string, std::string>
sort_files::year_and_month(const std::filesystem::directory_entry& file)
{
    auto f_time = std::filesystem::last_write_time(file);
    auto time_t = to_time_t(f_time);
    auto* gmt = std::gmtime(&time_t);
    std::stringstream year;
    std::stringstream month;
    year << std::put_time(gmt, "%Y");
    month << std::put_time(gmt, "%B");
    return std::pair{year.str(), month.str()};
}

template<typename TP>
std::time_t sort_files::to_time_t(TP tp)
{
    using namespace std::chrono;
    const auto t_point_cst = time_point_cast<system_clock::duration>(tp - TP::clock::now() + system_clock::now());
    return system_clock::to_time_t(t_point_cst);
}
