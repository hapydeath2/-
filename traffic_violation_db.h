#ifndef TRAFFIC_VIOLATION_DB_H
#define TRAFFIC_VIOLATION_DB_H

#include <string>
#include <map>
#include <vector>

class TrafficViolationDB {
public:
    void addViolation(const std::string& carNumber, const std::string& violation);
    void printDatabase() const;
    void printDataByCarNumber(const std::string& carNumber) const;
    void printDataInRange(const std::string& start, const std::string& end) const;
    void saveToFile(const std::string& filename) const;

private:
    std::map<std::string, std::vector<std::string>> db;
};

#endif // TRAFFIC_VIOLATION_DB_H
