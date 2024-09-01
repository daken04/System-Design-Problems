#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "VehicleType.h"
#include "Vehicle.h"

class ParkingSpot {
private:
    int spotNumber;
    VehicleType vehicleType;
    Vehicle* parkedVehicle;

public:
    // Default constructor
    ParkingSpot(int spotNumber, VehicleType type)
        : spotNumber(spotNumber), vehicleType(type), parkedVehicle(nullptr) {}

    bool isAvailable() const {
        return parkedVehicle == nullptr;
    }

    void parkVehicle(Vehicle* vehicle) {
        if (isAvailable() && vehicle->getType() == vehicleType) {
            parkedVehicle = vehicle;
        } else {
            throw std::invalid_argument("Invalid vehicle type or spot already occupied.");
        }
    }

    void unparkVehicle() {
        parkedVehicle = nullptr;
    }

    VehicleType getVehicleType() const {
        return vehicleType;
    }

    Vehicle* getParkedVehicle() const {
        return parkedVehicle;
    }

    int getSpotNumber() const {
        return spotNumber;
    }
};

#endif // PARKINGSPOT_H
