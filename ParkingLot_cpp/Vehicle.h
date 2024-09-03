#ifndef VEHICLE_H
#define VEHICLE_H

#include "VehicleType.h"
#include <bits/stdc++.h>

class Vehicle{
public:
    virtual ~Vehicle(){}
    virtual VehicleType getType() = 0;
    virtual string getlicensePlate() = 0;
};

#endif