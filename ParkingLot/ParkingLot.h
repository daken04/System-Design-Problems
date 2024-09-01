#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Level.h"
#include <vector>

class ParkingLot {
private:
    static ParkingLot* instance;
    std::vector<Level> levels;

    ParkingLot() {}

public:
    static ParkingLot* getInstance() {
        if (instance == nullptr) {
            instance = new ParkingLot();
        }
        return instance;
    }

    void addLevel(const Level& level) {
        levels.push_back(level);
    }

    bool parkVehicle(Vehicle* vehicle) {
        for (auto& level : levels) {
            if (level.parkVehicle(vehicle)) {
                return true;
            }
        }
        return false;
    }

    bool unparkVehicle(Vehicle* vehicle) {
        for (auto& level : levels) {
            if (level.unparkVehicle(vehicle)) {
                return true;
            }
        }
        return false;
    }

    void displayAvailability() const {
        for (const auto& level : levels) {
            level.displayAvailability();
        }
    }
};

// Initialize static member
ParkingLot* ParkingLot::instance = nullptr;

#endif // PARKINGLOT_H
