#ifndef SORT_FILES_UTILS_H
#define SORT_FILES_UTILS_H

bool has_ext(const std::string_view &f_ext, const std::vector<std::string> &extensions)
{
    for (const auto &ext : extensions) {
        if (f_ext == ext) {
            return true;
        }
    }
    return false;
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

// It's 2020 and to get file modification date I need to write below lines!
// Good job C++ commiters!
std::pair<std::string, std::string> get_year_and_month(
    const std::filesystem::directory_entry &file
)
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

const std::unordered_map<std::string_view, std::string_view> ext_to_dest{
    {".jpg", "photos"}, {".png", "photos"}, {".raw", "photos"}, {".arw", "photos"},
    {".mp4", "movies"}, {".mov", "movies"}, {".mts", "movies"}, {".vob", "movies"},
};

std::string_view dest_folder(const std::string_view &ext)
{
    return ext_to_dest.find(ext)->second;
}

const std::unordered_map<std::string_view, int> m_to_q{
    {"January", 1}, {"February", 1}, {"March", 1}, {"April", 2}, {"May", 2}, {"June", 2},
    {"July", 3}, {"August", 3}, {"September", 3}, {"October", 4}, {"November", 4},
    {"December", 4}
};

int quarter(const std::string_view &month)
{
    return m_to_q.find(month)->second;
}

void f_print(
    const std::filesystem::path &f_path,
    const std::string_view &year,
    const std::string_view &month,
    const std::string_view &quarter
)
{
    std::cout << "\t" << f_path << "\t" << year << ", " << month << "\t" << "quarter: "
              << quarter << "\n";
}

#endif //SORT_FILES_UTILS_H
