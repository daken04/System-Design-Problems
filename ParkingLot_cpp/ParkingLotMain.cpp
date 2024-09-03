#include "ParkingLot.h"
#include "level.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Truck.h"
#include<bits/stdc++.h>

int main() {
    ParkingLot* parkingLot = ParkingLot::getinstance();
    parkingLot->addLevel(new Level(1, 1, 1, 1)); // 50 car spots, 30 motorcycle spots, 20 truck spots
    parkingLot->addLevel(new Level(2, 5, 3, 2)); // 50 car spots, 30 motorcycle spots, 20 truck spots

    Car car("ABC123");
    Truck truck = Truck("XYZ789");
    Motorcycle motorcycle = Motorcycle("M1234");
    Car car2 = Car("ABC124");

    // Park vehicles
    parkingLot->parkVehicle(&car);
    parkingLot->parkVehicle(&truck);
    parkingLot->parkVehicle(&motorcycle);
     parkingLot->parkVehicle(&car2);

    // Display availability
    parkingLot->displayAvail();

    // Unpark vehicle
    parkingLot->unparkVehicle(&motorcycle);
    // parkingLot->unparkVehicle(&car2);

    // Display updated availability
    parkingLot->displayAvail();

    return 0;
}