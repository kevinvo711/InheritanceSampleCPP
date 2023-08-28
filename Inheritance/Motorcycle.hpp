#ifndef MOTORCYCLE_
#define MOTORCYCLE_

#include "Vehicle.hpp"
/**
      Calls the parameterized constructor Vehicle(...)
      Uses setGarageSpaces function to set garage space to 1.
      Uses setNumWheels function to set wheels to 2.
   */

class Motorcycle : public Vehicle {
public:
    Motorcycle(std::string name, std::string manufacturer, double top_speed, double weight, double mpg);

};

#endif