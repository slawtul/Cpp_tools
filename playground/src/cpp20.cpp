#include <vector>
#include <algorithm>
#include <iostream>

int main(int argc, char const* argv[])
{
    std::vector<int> vec{0, 6, 2, 3, 9, 5, 2, 7, 8, 4};
    const auto result = std::any_of(vec, [](auto x) { return x > 8; });
    std::cout << result << "\n";
    return 0;
}
