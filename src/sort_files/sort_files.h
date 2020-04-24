#ifndef SORT_FILES_H
#define SORT_FILES_H

#include <utility>
#include <iostream>
#include <filesystem>
#include <chrono>
#include <vector>
#include <unordered_map>

class Sort_files
{
public:
    explicit Sort_files(std::filesystem::path curr_path)
        : curr_path(std::move(curr_path))
    {}

    void start()
    {
        std::filesystem::create_directory(curr_path / "photos");
        std::filesystem::create_directory(curr_path / "movies");

        auto f_extensions = extensions();
        for (const auto &file : std::filesystem::directory_iterator(curr_path)) {
            if (file.is_directory()) {
                continue;
            }
            const auto &f_path = file.path();
            auto f_ext = f_path.extension().string();
            std::transform(f_ext.begin(), f_ext.end(), f_ext.begin(), ::tolower);
            if (f_ext.empty() || f_ext == ".") {
                continue;
            }
            if (has_ext(f_ext, f_extensions)) {
                const auto&[year, month] = year_and_month(file);
                const auto &quart = std::to_string(quarter(month));
                const auto res_path = curr_path.assign(dest_folder(f_ext)).append(year).append(quart);
                f_print(f_path, year, month, quart);
                std::filesystem::create_directories(curr_path.assign(res_path));
                auto f_name = f_path.filename().string();
                std::transform(f_name.begin(), f_name.end(), f_name.begin(), ::tolower);
                std::filesystem::rename(f_path, res_path / f_name);
                ++f_counter;
            }
        }
    }

    int count_f() const
    {
        return f_counter;
    }

private:
    std::filesystem::path curr_path{};
    int f_counter{0};

    const std::unordered_map<std::string_view, std::string_view> ext_to_dest{
        {".jpg", "photos"}, {".png", "photos"}, {".raw", "photos"}, {".arw", "photos"}, {".jpeg", "photos"},
        {".mp4", "movies"}, {".mov", "movies"}, {".mts", "movies"}, {".vob", "movies"}, {".avi", "movies"},
    };

    const std::unordered_map<std::string_view, int> m_to_q{
        {"January", 1}, {"February", 1}, {"March", 1}, {"April", 2}, {"May", 2}, {"June", 2},
        {"July", 3}, {"August", 3}, {"September", 3}, {"October", 4}, {"November", 4},
        {"December", 4}
    };

    static bool has_ext(const std::string_view &f_ext, const std::vector<std::string_view> &exts)
    {
        for (const auto &ext : exts) {
            if (f_ext == ext) {
                return true;
            }
        }
        return false;
    }

    int quarter(const std::string_view &month)
    {
        return m_to_q.find(month)->second;
    }

    std::vector<std::string_view> extensions()
    {
        std::vector<std::string_view> exts;
        for (const auto &entry : ext_to_dest) {
            exts.push_back(entry.first);
        }
        return exts;
    }

    std::string_view dest_folder(const std::string_view &ext)
    {
        return ext_to_dest.find(ext)->second;
    }

    static void f_print(
        const std::filesystem::path &f_path,
        const std::string_view &year,
        const std::string_view &month,
        const std::string_view &quarter)
    {
        std::cout << "\t" << f_path << "\t" << year << ", " << month << "\t" << "quarter: "
                  << quarter << "\n";
    }

    // It's 2020 and to get file modification date I need to write below lines!
    // Good job C++ commiters!
    std::pair<std::string, std::string> year_and_month(
        const std::filesystem::directory_entry &file)
    {
        auto f_time = std::filesystem::last_write_time(file);
        auto time_t = to_time_t(f_time);
        auto *gmt = std::gmtime(&time_t);
        std::stringstream year;
        std::stringstream month;
        year << std::put_time(gmt, "%Y");
        month << std::put_time(gmt, "%B");
        return std::pair{year.str(), month.str()};
    }

    template<typename TP>
    std::time_t to_time_t(TP tp)
    {
        using namespace std::chrono;
        const auto t_point_cst = time_point_cast<system_clock::duration>(
            tp - TP::clock::now() + system_clock::now()
        );
        return system_clock::to_time_t(t_point_cst);
    }

};


#endif //SORT_FILES_H
