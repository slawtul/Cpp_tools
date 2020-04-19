#include <iostream>
#include <filesystem>
#include <chrono>
#include <vector>
#include <unordered_map>
#include "sort_files_utils.h"

namespace fs = std::filesystem;

int main()
{
    std::cout << "program: sort_files\n";
    auto current_path = fs::current_path();
    fs::create_directory(current_path / "photos");
    fs::create_directory(current_path / "movies");

    int img_counter = 0;
    int mov_counter = 0;
    const auto start = std::chrono::high_resolution_clock::now();
    for (const auto &file : fs::directory_iterator(current_path)) {
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
            const auto &quart = std::to_string(quarter(month));
            f_print(f_path, year, month, quart);
            const auto res_path = current_path
                .assign(dest_folder(f_ext))
                .append(year)
                .append(quart);
            fs::create_directories(current_path.assign(res_path));
            auto f_name = f_path.filename().string();
            std::transform(f_name.begin(), f_name.end(), f_name.begin(), ::tolower);
            fs::rename(f_path, fs::current_path() / res_path / f_name);
        }
    }
    const auto stop = std::chrono::high_resolution_clock::now();
    const auto duration = duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "exec time: " << duration.count() << " ms\n";
    std::cout << "found: " << img_counter << " images\n";
    std::cout << "found: " << mov_counter << " movies\n";
    return 0;
}
