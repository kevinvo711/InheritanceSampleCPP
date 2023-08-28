#ifndef TRUCK_
#define TRUCK_

#include "Vehicle.hpp"

class Truck : public Vehicle
{
private:
    double m_cargo_capacity;
    double m_weight_of_held_cargo;

public:
    /**
    Calls the parameterized constructor Vehicle(...)
    Remember to set the cargo capacity.
    Uses setGarageSpaces function to set garage space to 8.
    Uses setNumWheels function to set wheels to 18.
    */
    Truck(std::string name, std::string manufacturer, double top_speed, double weight, double mpg, double cargo_capacity);

    /**
         Add the weight of the cargo the current weight_of_held_cargo_ ONLY if it does not exceed the capacity.
        Return true if you manage to add the cargo successfully, otherwise return false.
    */
    bool add_cargo(double weight_of_cargo);

    /**
         If weight_of_held_cargo_ isn't 0 then set it to 0, return true if you manage to clear it or else return false!
    */
    bool clear();

    /**
         return the cargo_capacity_ variable
    */
    double getCargoCapacity() const;

    /**
         returns the weight_of_held_cargo_ variable
    */
    double getHeldCargoWeight() const;
};
#endif