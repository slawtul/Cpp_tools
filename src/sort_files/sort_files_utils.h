#ifndef SORT_FILES_UTILS_H
#define SORT_FILES_UTILS_H

template<typename TP>
std::time_t to_time_t(TP tp)
{
    using namespace std::chrono;
    auto t_point_cst = time_point_cast<system_clock::duration>(
        tp - TP::clock::now() + system_clock::now()
    );
    return system_clock::to_time_t(t_point_cst);
}

bool is_file_with_ext(const std::filesystem::directory_entry &file,
                      const std::vector<std::string> &extensions)
{
    for (const auto &ext : extensions) {
        auto f_ext = file.path().extension().string();
        std::transform(f_ext.begin(), f_ext.end(), f_ext.begin(), ::tolower);
        if (f_ext == ext) {
            return true;
        }
    }
}

std::pair<std::string, std::string> get_year_and_month(const std::filesystem::directory_entry &file)
{
    auto f_time = std::filesystem::last_write_time(file);
    auto time_t = to_time_t(f_time);
    auto *gmt = std::gmtime(&time_t);
    std::stringstream year;
    std::stringstream month;
    year << std::put_time(gmt, "%Y");
    month << std::put_time(gmt, "%B");
    return std::pair(year.str(), month.str());
}

const std::map<std::string_view, int> month_to_quarter{
    {"January", 1}, {"February", 1}, {"March", 1}, {"April", 2}, {"May", 2}, {"June", 2},
    {"July", 3}, {"August", 3}, {"September", 3}, {"October", 4}, {"November", 4},
    {"December", 4}
};

int quarter(const std::string_view &month)
{
    for (const auto &[month_, quarter] : month_to_quarter) {
        if (month == month_) {
            return quarter;
        }
    }
    return 0;
}

#endif //SORT_FILES_UTILS_H
