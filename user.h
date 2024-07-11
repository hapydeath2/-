#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

using namespace std;
class User {
public:
    User(const string& name, int age);
    string getName() const;
    int getAge() const;
    bool operator<(const User& other) const;

private:
    string name;
    int age;
};

#endif // USER_H
