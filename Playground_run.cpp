#include <memory>
#include <iostream>
#include "Playground.h"

int main() {
  Playground pg{};
  pg.showABCWithRange();

  auto p1 = std::make_unique<person>("John", 41);
  auto p2 = std::make_unique<person>("Mike", 40);

  {
    pg.show_person_by_ptr(p1.get());
    pg.show_person_by_ref(*p2);
  }

  std::cout << p1->name << "\n";
  std::cout << p2->name << "\n";
}
