#include <iostream>
#include <filesystem>
#include <vector>
#include <map>
#include "sort_files_utils.h"

namespace fs = std::filesystem;

int main()
{
    std::cout << "sort_files\n";
    fs::create_directory(fs::current_path().append("photos"));
    fs::create_directory(fs::current_path().append("movies"));

    int img_cnt = 0;
    int mov_cnt = 0;
    for (const auto &file : fs::directory_iterator(fs::current_path())) {
        if (file.is_directory()) continue;
        if (is_file_with_ext(file, {".jpg", ".png", ".raw"})) {
            std::cout << file.path() << " : ";
            img_cnt++;
            auto[year, month] = get_year_and_month(file);
            std::cout << year << ", " << month << "\n";
            fs::create_directory(
                fs::current_path().assign("photos").append(year)
                    .append(std::to_string(quarter(month)))
            );
        }
        if (is_file_with_ext(file, {".mp4", ".mov"})) {
            mov_cnt++;
        }
    }
    std::cout << "found: " << img_cnt << " images\n";
    std::cout << "found: " << mov_cnt << " movies\n";
    return 0;
}
