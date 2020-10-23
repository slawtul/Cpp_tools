#include <memory>
#include <iostream>
#include "playground.h"
#include "simple_struct.h"

int main() {
  playground pg{};
  pg.show_ABC_with_range();

  auto p1 = std::make_unique<person>("John", 41);
  auto p2 = std::make_unique<person>("Mike", 40);

  {
    pg.show_person_by_ptr(p1.get());
    pg.show_person_by_ref(*p2);
  }

  std::cout << p1->name << "\n";
  std::cout << p2->name << "\n";

  std::cout << "Simple structure" << "\n";
  simple_struct ss{};
  std::cout << ss.name << "\n";
  std::cout << ss.d_number << "\n";
  std::cout << ss.number << "\n";
  std::cout << ss.truth << "\n";
  std::cout << ss.digit << "\n";
  std::cout << ss.sign << "\n";
}
