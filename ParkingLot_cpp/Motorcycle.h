#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"
#include "VehicleType.h"

class Motorcycle : public Vehicle{
private:
    string licensePlate;
public:
    Motorcycle(string licensePlate) : licensePlate(licensePlate) {}

    VehicleType getType() override{
        return VehicleType::MOTORCYCLE;
    }

    string getlicensePlate() override{
        return licensePlate;
    }
};

#endif