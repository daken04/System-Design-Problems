#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"
#include "VehicleType.h"

class Truck : public Vehicle{
private:
    string licensePlate;
public:
    Truck(string licensePlate) : licensePlate(licensePlate) {}

    VehicleType getType() override{
        return VehicleType::TRUCK;
    }

    string getlicensePlate() override{
        return licensePlate;
    }
};

#endif