#include <iostream>
#include <filesystem>
#include <vector>
#include <unordered_map>
#include "sort_files_utils.h"

namespace fs = std::filesystem;

int main()
{
    std::cout << "program: sort_files\n";
    fs::create_directory(fs::current_path().append("photos"));
    fs::create_directory(fs::current_path().append("movies"));

    int img_counter = 0;
    int mov_counter = 0;
    for (const auto &file : fs::directory_iterator(fs::current_path())) {
        if (file.is_directory()) {
            continue;
        }
        const auto &f_path = file.path();
        auto f_ext = f_path.extension().string();
        std::transform(f_ext.begin(), f_ext.end(), f_ext.begin(), ::tolower);
        if (f_ext.empty() || f_ext == ".") {
            continue;
        }
        if (has_ext(f_ext, {".jpg", ".png", ".raw", ".mov", ".mp4", ".arw"})) {
            img_counter++;
            const auto&[year, month] = get_year_and_month(file);
            const std::string_view qrt = std::to_string(quarter(month));
            f_print(f_path, year, month, qrt);
            fs::create_directories(
                fs::current_path().assign(dest_folder(f_ext)).append(year).append(qrt)
            );
        }
    }
    std::cout << "found: " << img_counter << " images\n";
    std::cout << "found: " << mov_counter << " movies\n";
    return 0;
}
