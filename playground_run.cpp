#include <memory>
#include <iostream>
#include <variant>
#include <vector>
#include "playground.h"
#include "simple_struct.h"

struct A
{
    void update()
    {
        std::cout << "from A struct..." << "\n";
    }
};

struct B
{
    void update()
    {
        std::cout << "from B struct..." << "\n";
    }
};

int main()
{
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

    std::cout << "\n---" << "variant" << "\n";
    using var = std::variant<A, B>;
    std::vector<var> items;
    items.emplace_back(A{});
    items.emplace_back(B{});
    items.emplace_back(B{});
    items.emplace_back(B{});
    items.emplace_back(A{});
    items.emplace_back(A{});
    items.emplace_back(A{});

    auto call_update = [](auto& item) { return item.update(); };

    for (auto& item : items) {
        std::visit(call_update, item);
    }

    std::cout << "\n---" << "another approach" << "\n";
    A a_arr[]{ A{}, A{}, A{}};
    B b_arr[]{ B{}, B{}, B{}};

    const auto do_update = [](auto& arr) {
        for (auto& item : arr) {
            item.update();
        }
    };

    do_update(a_arr);
    do_update(b_arr);


    return 0;

}
