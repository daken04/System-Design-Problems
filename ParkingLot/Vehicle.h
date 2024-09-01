#ifndef VEHICLE_H
#define VEHICLE_H

#include "VehicleType.h"
#include <string>

class Vehicle {
protected:
    std::string licensePlate;
    VehicleType type;

public:
    Vehicle(const std::string& licensePlate, VehicleType type)
        : licensePlate(licensePlate), type(type) {}

    virtual ~Vehicle() {}

    VehicleType getType() const {
        return type;
    }
};

#endif // VEHICLE_H
