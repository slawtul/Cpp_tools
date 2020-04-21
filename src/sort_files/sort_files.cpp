#include <iostream>
#include <filesystem>
#include <chrono>
#include <vector>
#include <unordered_map>
#include "sort_files_utils.h"

namespace fs = std::filesystem;

int main()
{
    auto current_path = fs::current_path();
    std::cout << "program: sort_files\n";
    std::cout << "---" << "\n";
    std::cout << "please confirm you want to run it inside " << current_path << " [y/n]\n";

    char confirm;
    std::cin >> confirm;

    if (confirm != 'y') {
        std::cout << "stopped" << "\n";
        return 0;
    }

    fs::create_directory(current_path / "photos");
    fs::create_directory(current_path / "movies");

    int f_counter = 0;
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
        if (has_ext(f_ext, extensions)) {
            const auto&[year, month] = year_and_month(file);
            const auto &quart = std::to_string(quarter(month));
            const auto
                res_path = current_path.assign(dest_folder(f_ext)).append(year).append(quart);
            f_print(f_path, year, month, quart);
            fs::create_directories(current_path.assign(res_path));
            auto f_name = f_path.filename().string();
            std::transform(f_name.begin(), f_name.end(), f_name.begin(), ::tolower);
            fs::rename(f_path, fs::current_path() / res_path / f_name);
            ++f_counter;
        }
    }
    const auto stop = std::chrono::high_resolution_clock::now();
    const auto duration = duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "---" << "\n";
    std::cout << "found files: " << f_counter << "\n";
    std::cout << "exec time [ms]: " << duration.count() << "\n";
    return 0;
}
