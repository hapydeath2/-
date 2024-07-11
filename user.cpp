#include "user.h"
#include <iostream>

using namespace std;
User::User(const string& name, int age) : name(name), age(age) {}

string User::getName() const {
    return name;
}

int User::getAge() const {
    return age;
}

bool User::operator<(const User& other) const {
    return age < other.age;
}
