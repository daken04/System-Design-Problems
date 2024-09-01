#include "ParkingLot.h"
#include "Level.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Truck.h"

int main() {
    ParkingLot* parkingLot = ParkingLot::getInstance();
    parkingLot->addLevel(Level(1, 1, 1, 1)); // 50 car spots, 30 motorcycle spots, 20 truck spots
    parkingLot->addLevel(Level(2, 5, 3, 2)); // 50 car spots, 30 motorcycle spots, 20 truck spots

    Car car("ABC123");
    Truck truck("XYZ789");
    Motorcycle motorcycle("M1234");
    Car car2("ABC124");

    // Park vehicles
    parkingLot->parkVehicle(&car);
    parkingLot->parkVehicle(&truck);
    parkingLot->parkVehicle(&motorcycle);
     parkingLot->parkVehicle(&car2);

    // Display availability
    parkingLot->displayAvailability();

    // Unpark vehicle
    parkingLot->unparkVehicle(&motorcycle);
    parkingLot->unparkVehicle(&car2);

    // Display updated availability
    parkingLot->displayAvailability();

    return 0;
}