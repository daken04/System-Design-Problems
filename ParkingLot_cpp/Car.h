#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include "VehicleType.h"

class Car : public Vehicle{
private:
    string licensePlate;
public:
    Car(string licensePlate) : licensePlate(licensePlate) {}

    VehicleType getType() override{
        return VehicleType::CAR;
    }

    string getlicensePlate() override{
        return licensePlate;
    }
};

#endif