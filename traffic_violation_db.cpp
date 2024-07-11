#include "traffic_violation_db.h"
#include <iostream>
#include <fstream>

void TrafficViolationDB::addViolation(const std::string& carNumber, const std::string& violation) {
    db[carNumber].push_back(violation);
}

void TrafficViolationDB::printDatabase() const {
    for (const auto& entry : db) {
        std::cout << "Car Number: " << entry.first << std::endl;
        for (const auto& violation : entry.second) {
            std::cout << " - " << violation << std::endl;
        }
    }
}

void TrafficViolationDB::printDataByCarNumber(const std::string& carNumber) const {
    auto it = db.find(carNumber);
    if (it != db.end()) {
        std::cout << "Car Number: " << carNumber << std::endl;
        for (const auto& violation : it->second) {
            std::cout << " - " << violation << std::endl;
        }
    }
    else {
        std::cout << "No data for car number: " << carNumber << std::endl;
    }
}

void TrafficViolationDB::printDataInRange(const std::string& start, const std::string& end) const {
    for (auto it = db.lower_bound(start); it != db.upper_bound(end); ++it) {
        std::cout << "Car Number: " << it->first << std::endl;
        for (const auto& violation : it->second) {
            std::cout << " - " << violation << std::endl;
        }
    }
}

void TrafficViolationDB::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }
    for (const auto& entry : db) {
        file << "Car Number: " << entry.first << std::endl;
        for (const auto& violation : entry.second) {
            file << " - " << violation << std::endl;
        }
    }
    file.close();
}
