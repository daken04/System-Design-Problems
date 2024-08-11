## First we will make everything related to vehicles
1. vehicle_type: This has 3 types of vehicles, car, truck and motorcycle
2. vehicle: Abstact class from all three kinds of vehicles
3. Car, Motorcycle and Truck

## Next we will make our Parking lot related stuff
1. parking_spot: which has info of whether the parking spot is empty or not, if not then what vehicle is there
2. level: it will check for each spot in the level manage those spots
3. parking_lot: manage each level, function like add_level, park, unpark (This is singleton class)


Key Learning Points:
- ABC Class: When you define a class that inherits from ABC, it becomes an abstract base class, meaning it can include abstract methods that have no implementation.
- @abstractmethod Decorator: This decorator is used to declare methods as abstract within the abstract base class. Any class inheriting from this base class must implement all abstract methods, or it too will be abstract and non-instantiable.
- Purpose of Abstract Base Classes:
    Interface Definition: They allow you to define a common interface for a set of subclasses. Subclasses are required to implement the interface.
    Enforcing Consistency: By using abstract methods, you ensure that all subclasses implement certain methods, maintaining consistency across implementations.

- Enum assigns values to the names you define. Each name in an Enum is associated with a specific value, which can be a number, string, or any other constant value you choose.



