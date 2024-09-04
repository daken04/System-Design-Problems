#ifndef LEVEL_H
#define LEVEL_H

#include<bits/stdc++.h>
#include "ParkingSpot.h"
#include "VehicleType.h"
using namespace std;

class Level{
private:
    int levelNum;
    vector<ParkingSpot*> carSpots;
    vector<ParkingSpot*> MotorcycleSpots;
    vector<ParkingSpot*> truckSpots;

public:
    Level(int floor, int numCars, int numMotorcycle, int truck) : levelNum(floor){
        int count = 0;
        while(numCars--){
            carSpots.push_back(new ParkingSpot(count,VehicleType::CAR));
            count++;
        }

        while(numMotorcycle--){
            MotorcycleSpots.push_back(new ParkingSpot(count,VehicleType::MOTORCYCLE));
            count++;
        }

        while(truck--){
            truckSpots.push_back(new ParkingSpot(count,VehicleType::TRUCK));
            count++;
        }
    }

    bool parkVehicle(Vehicle* vehicle){
        if(vehicle->getType()==VehicleType::CAR){
            for(auto z: carSpots){
                if(z->isAvailable()){
                    z->parkVehicle(vehicle);
                    return true;
                }
            }
        }
        else if(vehicle->getType()==VehicleType::MOTORCYCLE){
            for(auto z: MotorcycleSpots){
                if(z->isAvailable()){
                    z->parkVehicle(vehicle);
                    return true;
                }
            }
        }
        else{
            for(auto z: truckSpots){
                if(z->isAvailable()){
                    z->parkVehicle(vehicle);
                    return true;
                }
            }
        }

        return false;
    }

    bool unParkVehicle(Vehicle* vehicle){
        if(vehicle->getType()==VehicleType::CAR){
            for(auto z: carSpots){
                if(!z->isAvailable() && z->getParkedVehicle()==vehicle){
                    z->unparkVehicle();
                    return true;
                }
            }
        }
        else if(vehicle->getType()==VehicleType::MOTORCYCLE){
            for(auto z: MotorcycleSpots){
                if(!z->isAvailable() && z->getParkedVehicle()==vehicle){
                    z->unparkVehicle();
                    return true;
                }
            }
        }
        else{
            for(auto z: truckSpots){
                if(!z->isAvailable() && z->getParkedVehicle()==vehicle){
                    z->unparkVehicle();
                    return true;
                }
            }
        }
        return false;
    }

    void diplayAvailability(){
        cout<<"Level"<<levelNum<<endl;
        cout<<"Availability:"<<endl;
        cout<<"Car Spots available ->"<<endl;
        for(auto z: carSpots){
            cout<<"Spot Number: "<<z->getSpotNumber()<<"("<< (z->isAvailable() ? "Available" : "Occupied")<<")"<<endl;
        }

        cout<<"MotorCycle Spots available ->"<<endl;
        for(auto z: MotorcycleSpots){
            cout<<"Spot Number: "<<z->getSpotNumber()<<"("<< (z->isAvailable() ? "Available" : "Occupied")<<")"<<endl;
        }

        cout<<"Truck Spots available ->"<<endl;
        for(auto z: truckSpots){
            cout<<"Spot Number: "<<z->getSpotNumber()<<"("<< (z->isAvailable() ? "Available" : "Occupied")<<")"<<endl;
        }
    }
};

#endif