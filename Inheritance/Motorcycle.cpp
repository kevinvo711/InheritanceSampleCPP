#include "Motorcycle.hpp"

Motorcycle::Motorcycle(std::string name, std::string manufacturer, double top_speed, double weight, double mpg)
    : Vehicle{name, manufacturer, top_speed, weight, mpg, 0}
{
    setGarageSpaces(1);
    setNumWheels(2);
}
