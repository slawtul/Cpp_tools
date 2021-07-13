#include <vector>
#include <ranges>

int main(int argc, char const* argv[])
{
    std::vector<int> int_vec{0, 6, 2, 3, 9, 5, 2, 7, 8, 4};
    std::ranges::sort(int_vec);
    return 0;
}
