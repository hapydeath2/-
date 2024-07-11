#include "traffic_violation_db.h"
#include <iostream>
#include <fstream>

using namespace std;
int TrafficViolationDB::findCarIndex(const string& carNumber) const {
    for (size_t i = 0; i < carNumbers.size(); ++i) {
        if (carNumbers[i] == carNumber) {
            return i;
        }
    }
    return -1;
}

void TrafficViolationDB::addViolation(const string& carNumber, const string& violation) {
    int index = findCarIndex(carNumber);
    if (index != -1) {
        violations[index].push_back(violation);
    }
    else {
        carNumbers.push_back(carNumber);
        violations.emplace_back(vector<string>{violation});
    }
}

void TrafficViolationDB::printDatabase() const {
    for (size_t i = 0; i < carNumbers.size(); ++i) {
        cout << "Car Number: " << carNumbers[i] << endl;
        for (const auto& violation : violations[i]) {
            cout << " - " << violation << endl;
        }
    }
}

void TrafficViolationDB::printDataForCar(const string& carNumber) const {
    int index = findCarIndex(carNumber);
    if (index != -1) {
        cout << "Data for car number " << carNumber << ":" << endl;
        for (const auto& violation : violations[index]) {
            cout << " - " << violation << endl;
        }
    }
    else {
        cout << "No data found for car number " << carNumber << endl;
    }
}

void TrafficViolationDB::printDataForRange(const string& startNumber, const string& endNumber) const {
    for (size_t i = 0; i < carNumbers.size(); ++i) {
        if (carNumbers[i] >= startNumber && carNumbers[i] <= endNumber) {
            cout << "Car Number: " << carNumbers[i] << endl;
            for (const auto& violation : violations[i]) {
                cout << " - " << violation << endl;
            }
        }
    }
}

void TrafficViolationDB::saveToFile(const string& filename) const {
    ofstream file(filename);
    for (size_t i = 0; i < carNumbers.size(); ++i) {
        file << "Car Number: " << carNumbers[i] << endl;
        for (const auto& violation : violations[i]) {
            file << " - " << violation << endl;
        }
    }
    file.close();
}
