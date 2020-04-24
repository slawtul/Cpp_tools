#include "sort_files.h"

namespace fs = std::filesystem;

int main()
{
    auto current_path = fs::current_path();
    std::cout << "program: sort_files\n";
    std::cout << "please confirm you want to run it inside " << current_path << " [y/n]\n";

    char confirm;
    std::cin >> confirm;

    if (confirm != 'y') {
        std::cout << "stopped" << "\n";
        return 0;
    }

    const auto start = std::chrono::high_resolution_clock::now();
    Sort_files sf{current_path};
    sf.start();
    const auto stop = std::chrono::high_resolution_clock::now();

    std::cout << "found files: " << sf.count_f() << "\n";
    std::cout << "exec time [ms]: "
              << duration_cast<std::chrono::milliseconds>(stop - start).count() << "\n";
    return 0;
}
