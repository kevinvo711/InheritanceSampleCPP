#include "Truck.hpp"

Truck::Truck(std::string name, std::string manufacturer, double top_speed, double weight, double mpg, double cargo_capacity)
    : Vehicle{name, manufacturer, top_speed, weight, mpg, 0}, m_cargo_capacity{cargo_capacity}
{
    setGarageSpaces(8);
    setNumWheels(18);
}

bool Truck::add_cargo(double weight_of_cargo){
    if (weight_of_cargo + m_weight_of_held_cargo > m_cargo_capacity){
        return false;
    } else {
        m_weight_of_held_cargo += weight_of_cargo;
        return true;
    }
}

bool Truck::clear(){
    if(m_weight_of_held_cargo != 0){
        m_weight_of_held_cargo = 0;
        return true;
    }
    std::cout << "Truck clear returned false, should never happen";
    return false;
    // m_weight_of_held_cargo = 0;
    // return true;
}

double Truck::getCargoCapacity() const{
    return m_cargo_capacity;
}

double Truck::getHeldCargoWeight() const{
    return m_weight_of_held_cargo;
}