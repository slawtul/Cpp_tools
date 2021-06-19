#include <iostream>

#include "playground.h"

void playground::show_ABC_with_range()
{
    std::cout << std::ranges::size("ABC") << "\n";
}

void playground::show_person_by_ptr(person* p)
{
    if (p) {
        std::cout << p->name << ", " << p->age << "\n";
        p->name = "John1";
    }
}

void playground::show_person_by_ref(person& p)
{
    std::cout << p.name << ", " << p.age << "\n";
    p.name = "Mike1";
}

void playground::show_person_by_uptr(const std::unique_ptr<person>& p)
{
    std::cout << p->name << ", " << p->age << "\n";
    p->name = "Uniq person name";
}
