#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include <bits/stdc++.h>
#include "Vehicle.h"
#include "VehicleType.h"

class ParkingSpot{
private:
    int spotNumber;
    VehicleType type;
    Vehicle* parkedVehicle;

public:
    ParkingSpot(int spotNumber,VehicleType type) : spotNumber(spotNumber), type(type) {}

    // function in spot
    bool isAvailable(){
        if(parkedVehicle==NULL){
            return true;
        }

        return false;
    }

    void parkVehicle(Vehicle *vehicle){
        if(isAvailable() && vehicle->getType()==type){
            parkedVehicle = vehicle;
        } else{
            throw invalid_argument("Invalid vehicle type or spot already occupied.");
        }
    }

    void unparkVehicle(){
        parkedVehicle = NULL;
    }

    VehicleType getVehicleType(){
        return type;
    }

    Vehicle* getParkedVehicle(){
        if(!isAvailable()){
            return parkedVehicle;
        }
        else{
            throw invalid_argument("No vehicle is parked");
        }
    }

    int getSpotNumber(){
        return spotNumber;
    }
};

#endif