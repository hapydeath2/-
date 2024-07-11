#include <iostream>
#include "priority_queue.h"
#include "user.h"
#include "traffic_violation_db.h"

int main() {
    // Тестирование очереди с приоритетами
    PriorityQueue<User> pq;
    pq.push(User("Alice", 30), 2);
    pq.push(User("Bob", 25), 1);
    pq.push(User("Charlie", 35), 3);

    std::cout << "Priority Queue Test:" << std::endl;
    std::cout << "Highest priority user: " << pq.pop().getName() << std::endl;
    std::cout << "Next highest priority user: " << pq.pop().getName() << std::endl;
    std::cout << "Next highest priority user: " << pq.pop().getName() << std::endl;

    // Работа с базой данных ГАИ
    TrafficViolationDB db;
    db.addViolation("ABC123", "Speeding");
    db.addViolation("ABC123", "Running a red light");
    db.addViolation("XYZ789", "Illegal parking");

    std::cout << "\nTraffic Violation Database:" << std::endl;
    db.printDatabase();

    std::cout << "\nData for car number ABC123:" << std::endl;
    db.printDataByCarNumber("ABC123");

    std::cout << "\nData for car numbers between ABC000 and ABC999:" << std::endl;
    db.printDataInRange("ABC000", "ABC999");

    db.saveToFile("violations.txt");

    return 0;
}
