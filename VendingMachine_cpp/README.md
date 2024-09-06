In C++, circular dependencies occur because the C++ compiler requires that types be fully defined before they are used in certain ways (such as defining variables of that type). When two classes include each other directly, it creates a problem for the compiler, as it cannot figure out which class to fully define first.

In Java, circular dependencies are less of a problem because of how Java handles class loading and compilation:

Dynamic Class Loading: Java classes are loaded dynamically at runtime, so it does not require the same strict ordering of class definitions as C++ does. The Java Virtual Machine (JVM) can resolve classes in a circular dependency at runtime without needing to know the full details of the other class at compile time.

In this code this is why we are doing circular dependency resolution by:

1) forward declaration in .h files
2) then defining in .cpp files , for vending machine and states

to compile:
g++ -std=c++11 -o vending_machine vending_machine_demo.cpp vending_machine.cpp ready_state.cpp idle_state.cpp dispense_state.cpp return_change_state.cpp