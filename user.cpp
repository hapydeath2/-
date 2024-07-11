#include "user.h"

User::User(const std::string& name, int age) : name(name), age(age) {}

std::string User::getName() const {
    return name;
}

int User::getAge() const {
    return age;
}

bool User::operator<(const User& other) const {
    return age < other.age;
}
