#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include<bits/stdc++.h>
#include "level.h"
using namespace std;

class ParkingLot{
private:
    static ParkingLot* instance;
    static mutex mtx;  // Mutex to protect the instance creation
    vector<Level*> levels;

    ParkingLot(){}

    // Delete copy constructor
    ParkingLot(const ParkingLot&) = delete;

    // Delete copy assignment operator
    ParkingLot& operator=(const ParkingLot&) = delete;

public:
    static ParkingLot* getinstance(){
        lock_guard<mutex> lock(mtx);
        if(instance==NULL){
            cout<<"created"<<endl;
            instance = new ParkingLot();;
            return instance;
        }
        return instance;
    }

    void addLevel(Level* level){
        levels.push_back(level);
    }

    bool parkVehicle(Vehicle* vehicle){
        for(auto level: levels){
            if(level->parkVehicle(vehicle)){
                return true;
            }
        }
        return false;
    }

    bool unparkVehicle(Vehicle* vehicle){
        for(auto level : levels){
            if(level->unParkVehicle(vehicle)){
                return true;
            }
        }
        return false;
    }

    void displayAvail(){
        for(auto level : levels){
            level->diplayAvailability();
        }
    }
};

ParkingLot* ParkingLot::instance = NULL;
mutex ParkingLot::mtx;

#endif