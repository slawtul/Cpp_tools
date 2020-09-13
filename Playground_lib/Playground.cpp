#include <iostream>
#include <ranges>

#include "Playground.h"

void Playground::showABCWithRange() {
  std::cout << std::ranges::size("ABC") << "\n";
}

void Playground::show_person_by_ptr(person *p) {
  if (p) {
    std::cout << p->name << ", " << p->age << "\n";
    p->name = "John1";
  }
}

void Playground::show_person_by_ref(person &p) {
  std::cout << p.name << ", " << p.age << "\n";
  p.name = "Mike1";
}
