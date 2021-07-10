#include <iostream>
#include <memory>

struct Widget
{
    int id;
};

void call_PTR_widget(Widget* widget)
{
    if (widget) {
        std::cout << "passing with pointer *" << "\n";
        std::cout << widget->id << "\n";
        widget->id = 1;
    }
}

void call_REF_widget(Widget& widget)
{
    std::cout << "passing with reference &" << "\n";
    std::cout << widget.id << "\n";
    widget.id = 1;
}

int main()
{
    //
    // PASSING STACKED OBJECT TO FUNCTION WITH * AND &
    //
    std::cout << "// PASSING STACKED OBJECT TO FUNCTION WITH * AND &" << "\n";

    Widget widget{};

    call_PTR_widget(&widget);
    std::cout << widget.id << "\n";

    widget.id = 0; // reset

    call_REF_widget(widget);
    std::cout << widget.id << "\n";

    //
    // PASSING HEAPED OBJECT TO FUNCTION WITH * AND &
    //
    std::cout << "// PASSING HEAPED OBJECT TO FUNCTION WITH * AND &" << "\n";

    auto uptr_widget = std::make_unique<Widget>();

    call_PTR_widget(uptr_widget.get()); // get() - give me a raw pointer
    std::cout << uptr_widget->id << "\n";

    uptr_widget->id = 0; // reset

    call_REF_widget(*uptr_widget); // *uptr_widget - give me value
    std::cout << uptr_widget->id << "\n";
}
