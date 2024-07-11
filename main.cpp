#include <iostream>
#include "priority_queue.h"
#include "user.h"
#include "traffic_violation_db.h"

using namespace std;

int main()
{
    PriorityQueue<User*> userQueue;
    userQueue.push(new User("Alice", 3), 3);
    userQueue.push(new User("Bob", 1), 1);
    userQueue.push(new User("Charlie", 2), 2);

    cout << "Priority Queue Test:" << endl;
    User* user;
    while (!userQueue.empty()) {
        user = userQueue.pop();
        cout << "Highest priority user: " << user->getName() << endl;
        delete user;
    }

    // Тест базы данных ГАИ
    TrafficViolationDB db;
    db.addViolation("ABC123", "Speeding");
    db.addViolation("XYZ789", "Illegal parking");
    db.addViolation("ABC123", "Running a red light");

    cout << "\nTraffic Violation Database:" << endl;
    db.printDatabase();

    cout << "\nData for car number ABC123:" << endl;
    db.printDataForCar("ABC123");

    cout << "\nData for car numbers between ABC000 and ABC999:" << endl;
    db.printDataForRange("ABC000", "ABC999");

    return 0;
}
