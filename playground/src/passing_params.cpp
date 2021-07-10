#include <iostream>

struct Widget
{
    int id;
};

void call_ptr_widget(Widget* widget)
{
    if (widget) {
        std::cout << "passing with pointer *" << "\n";
        std::cout << widget->id << "\n";
        widget->id = 1;
    }
}

void call_ref_widget(Widget& widget)
{
    std::cout << "passing with reference &" << "\n";
    std::cout << widget.id << "\n";
    widget.id = 1;
}

int main()
{
    Widget widget{};
    call_ptr_widget(&widget);
    std::cout << widget.id << "\n";

    widget.id = 0; // reset

    call_ref_widget(widget);
    std::cout << widget.id << "\n";

}
