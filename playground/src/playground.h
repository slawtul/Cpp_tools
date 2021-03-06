#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <string>
#include <utility>
#include <memory>

struct person
{
    std::string name;
    int age;

    person(std::string name_, int age_) : name{std::move(name_)}, age{age_}
    {
    }
};

struct playground
{
    void show_ABC_with_range();
    void show_person_by_ref(person& p);
    void show_person_by_ptr(person* p);
    void show_person_by_uptr(const std::unique_ptr<person>& p);
};

#endif // PLAYGROUND_H
