#include "Person.hpp"
#include "Birthday.hpp"
#include <string>

Person::Person() {
    this->birthday.day = 0;
    this->birthday.month = 0;
    this->name = "";
}

Person::Person(std::string name, Birthday birthday) {
    this->name = name;
    this->birthday = birthday;
}

std::string Person::getName() {
    return name;
}

Birthday Person::getBirthday() {
    return birthday;
}

void Person::setName(std::string name) {
    this->name = name;
}

void Person::setBirthday(Birthday birthday) {
    this->birthday = birthday;
}

void Person::operator=(const Person& right) {
    this->setName(right.name);
    this->setBirthday(right.birthday);
}