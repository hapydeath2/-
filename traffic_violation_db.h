#ifndef TRAFFIC_VIOLATION_DB_H
#define TRAFFIC_VIOLATION_DB_H

#include <vector>
#include <string>

using namespace std;
class TrafficViolationDB {
public:
    void addViolation(const string& carNumber, const string& violation);
    void printDatabase() const;
    void printDataForCar(const string& carNumber) const;
    void printDataForRange(const string& startNumber, const string& endNumber) const;
    void saveToFile(const string& filename) const;

private:
    vector<string> carNumbers;
    vector<vector<string>> violations;

    int findCarIndex(const string& carNumber) const;
};

#endif // TRAFFIC_VIOLATION_DB_H
