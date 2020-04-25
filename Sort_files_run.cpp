#include "Sort_files.h"

namespace fs = std::filesystem;
namespace ch = std::chrono;

int main()
{
    auto c_path = fs::current_path();
    std::cout << "program: sort_files\n";
    std::cout << "please confirm you want to run it inside " << c_path << " [y/n]\n";

    char confirm;
    std::cin >> confirm;

    if (confirm != 'y') {
        std::cout << "stopped" << "\n";
        return 0;
    }

    const auto start = ch::high_resolution_clock::now();
    Sort_files sf{c_path};
    sf.start();
    const auto stop = ch::high_resolution_clock::now();

    std::cout << "found files: " << sf.count_f() << "\n";
    std::cout << "exec time [ms]: "
              << duration_cast<ch::milliseconds>(stop - start).count() << "\n";
    return 0;
}
