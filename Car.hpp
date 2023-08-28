#ifndef CAR_
#define CAR_

#include "Vehicle.hpp"
/**
      Calls the parameterized constructor Vehicle(...)
      Uses setGarageSpaces function to set garage space to 2.
      Uses setNumWheels function to set wheels to 4.
   */

class Car : public Vehicle{
public:
    Car(std::string name, std::string manufacturer, double top_speed, double weight, double mpg);
    //: Vehicle{name, manufacturer, top_speed, weight, mpg, 0.0}

};

#endif