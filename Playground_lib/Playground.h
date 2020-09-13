#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <string>
#include <utility>

struct person {
  std::string name;
  int age;

  person(std::string name_, int age_) : name(std::move(name_)), age(age_) {}
};

class Playground {
public:
  void showABCWithRange();

  void show_person_by_ref(person &p);

  void show_person_by_ptr(person *p);
};

#endif // PLAYGROUND_H
