from vehicle_type import VehicleType
from vehicle import Vehicle

class ParkingSpot:
    def __init__(self, spot_number: int):
        self.spot_number = spot_number
        self.vehicle_type = VehicleType.CAR
        self.parked_vehicle = None

    def is_available(self) -> bool:
        if not self.parked_vehicle:
            return True
        return False
    
    def park_vehicle(self, vehicle: Vehicle):
        if self.is_available() and vehicle.get_type() == self.vehicle_type:
            self.parked_vehicle = vehicle
        else:
            if not self.is_available():
                raise ValueError("Parking is not available")
            else:
                raise ValueError("Vehicle type is not right for the parking spot")

    def unpark_vehicle(self):
        self.parked_vehicle = None

    def get_vehicle_type(self) -> VehicleType:
        return self.vehicle_type
        
    def get_parked_vehicle(self) -> Vehicle:
        return self.parked_vehicle
        
    def get_spot_number(self) -> int:
        return self.spot_number


    
