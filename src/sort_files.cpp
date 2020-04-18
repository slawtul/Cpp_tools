#include <iostream>
#include <sys/stat.h>
#include <filesystem>

namespace fs = std::filesystem;

template<typename TP>
std::time_t to_time_t(TP tp)
{
    using namespace std::chrono;
    auto t_point_cst = time_point_cast<system_clock::duration>(
        tp - TP::clock::now() + system_clock::now()
    );
    return system_clock::to_time_t(t_point_cst);
}

int main()
{
    std::cout << "sort_files\n";
    int counter = 0;
    for (const auto &f : fs::directory_iterator(fs::current_path())) {
        std::cout << f.path() << "\n";
        if (f.path().extension() == ".jpg") {
            counter++;
            auto f_time = fs::last_write_time(f);
            std::time_t tt = to_time_t(f_time);
            std::tm *gmt = std::gmtime(&tt);
            std::stringstream buffer;
            buffer << std::put_time(gmt, "%A, %d %B %Y %H:%M");
            std::string formattedFileTime = buffer.str();
            std::cout << formattedFileTime << '\n';

        }
    }
    std::cout << "found: " << counter << " files\n";
    return 0;
}
