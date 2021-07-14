//
// Created by slawtul on 14.07.2021.
//
#include <iostream>

int main(int argc, char const* argv[])
{
    const std::string str{"Modern C++"};

    std::string s1{"Modern C++", 3};
    std::string s2{str, 3};

    std::cout << "S1: " << s1 << "\n";
    std::cout << "S2: " << s2 << "\n";

    return 0;
}
