from parking_lot import ParkingLot
from level import Level
from car import Car
from motorcycle import Motorcycle
from truck import Truck

class ParkingLotDemo:
    def run():
        parking_lot = ParkingLot()
        parking_lot.add_level(Level(1,1))
        parking_lot.add_level(Level(2,2))

        car1 = Car("10101")
        car2 = Car("11011")
        motorcycle = Motorcycle("20202")
        truck = Truck("30303")

        parking_lot.park_vehicle(car1)
        parking_lot.park_vehicle(motorcycle)
        parking_lot.park_vehicle(truck)
        parking_lot.park_vehicle(car2)

        parking_lot.display_availability()

        parking_lot.unpark_vehicle(car1)

        parking_lot.display_availability()


if __name__ == "__main__":
    ParkingLotDemo.run()