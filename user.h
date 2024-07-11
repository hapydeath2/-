#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(const std::string& name, int age);
    std::string getName() const;
    int getAge() const;
    bool operator<(const User& other) const;

private:
    std::string name;
    int age;
};

#endif // USER_H
