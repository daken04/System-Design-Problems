#ifndef LEVEL_H
#define LEVEL_H

#include "ParkingSpot.h"
#include <vector>
#include <iostream>

class Level {
private:
    int floor;
    std::vector<ParkingSpot> parkingSpots;

public:
    Level(int floor, int numCarSpots, int numMotorcycleSpots, int numTruckSpots)
        : floor(floor) {
        // Create car spots
        for (int i = 0; i < numCarSpots; ++i) {
            ParkingSpot spot(i, VehicleType::CAR);
            parkingSpots.push_back(spot);
        }

        // Create motorcycle spots
        for (int i = numCarSpots; i < numCarSpots + numMotorcycleSpots; ++i) {
            ParkingSpot spot(i, VehicleType::MOTORCYCLE);
            parkingSpots.push_back(spot);
        }

        // Create truck spots
        for (int i = numCarSpots + numMotorcycleSpots; i < numCarSpots + numMotorcycleSpots + numTruckSpots; ++i) {
            ParkingSpot spot(i, VehicleType::TRUCK);
            parkingSpots.push_back(spot);
        }
    }

    bool parkVehicle(Vehicle* vehicle) {
        for (auto& spot : parkingSpots) {
            if (spot.isAvailable() && spot.getVehicleType() == vehicle->getType()) {
                spot.parkVehicle(vehicle);
                return true;
            }
        }
        return false;
    }

    bool unparkVehicle(Vehicle* vehicle) {
        for (auto& spot : parkingSpots) {
            if (!spot.isAvailable() && spot.getParkedVehicle() == vehicle) {
                spot.unparkVehicle();
                return true;
            }
        }
        return false;
    }

    void displayAvailability() const {
        std::cout << "Level " << floor << " Availability:" << std::endl;
        for (const auto& spot : parkingSpots) {
            std::cout << "Spot " << spot.getSpotNumber() << ": " 
                      << (spot.isAvailable() ? "Available" : "Occupied") << std::endl;
        }
    }
};

#endif // LEVEL_H
