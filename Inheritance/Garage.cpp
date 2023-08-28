/**
 * File: Garage.cpp
 * Author: Kevin Vo
 * Description: Inheritance and dynamic memory demonstration working with 
 * Truck, Car, Bus, and Motorcycle which all work with this implemented Garage class
*/
#include "Garage.hpp"
#include <vector>

Garage::Garage(size_t capacity) : capacity_{capacity}, arr_{new Vehicle[capacity]}
{
    // arr_ {new Vehicle[capacity]{}};
    // arr_ = new Vehicle[capacity_];
}


void Garage::arrange(){
    std::vector<Vehicle> noGaps; //will store a vector of nonempty Vehicles
    int emptyCounter = 0;
    for(int i{0}; i < capacity_; ++i){
        if(arr_[i] == Vehicle()){
            emptyCounter++;
            // continue;
        }
        else{
            noGaps.push_back(arr_[i]);
        }
    }
    Vehicle* copy{new Vehicle[capacity_]{}};
    Vehicle tmp{};
    for(int i{0}; i < emptyCounter; ++i){
        copy[i] = tmp;
    }
    for(int i{emptyCounter}; i < capacity_; ++i){
        int offset = i - capacity_ + noGaps.size();
        copy[i] = noGaps.at(offset);
        copy[i].setGarageSpaces(noGaps.at(offset).getGaragePositions());
        copy[i].setNumWheels(noGaps.at(offset).getNumWheels());
    }
    delete [] arr_;
    arr_ = copy;
}

bool Garage::addVehicle(Vehicle to_add){
    int spaceValue = to_add.getSpaces();
    if(isFull()){
        return false;
    }
    else if (num_vehicles_ + spaceValue > capacity_)
    {
        return false;
    }
    else{
        /**insert from front to back, so create a new Vehicle array 
         * add to front, copy preexisting array to back of copy_, set copy_ to arr_
         * */

        std::vector<Vehicle> copyVector;
        Vehicle* copy_ {new Vehicle[capacity_]};
        for(int i{0}; i < spaceValue; i++){
            copyVector.push_back(to_add);
        }

        Vehicle tmp{};
        // Vehicle* ptr = &Vehicle{};
        for(int i{0}; i < capacity_; i++){
            if(arr_[i] != tmp){ //create 1 single Vehicle() object and compare to that instead?
                copyVector.push_back(arr_[i]);
            }
        }
        for(int i{0}; i < copyVector.size(); ++i){
            copy_[i] = copyVector.at(i);
            copy_[i].setGarageSpaces(copyVector.at(i).getGaragePositions());
            copy_[i].setNumWheels(copyVector.at(i).getNumWheels());
        }
        delete[] arr_; //free old memory before reassigning
        arr_ = copy_;
        num_vehicles_ += spaceValue;
        return true;
    }
}

bool Garage::removeVehicle(Vehicle to_remove){
    if(num_vehicles_ == 0){
        return false;
    } else {
        //I will only remove 1 instance of vehicle in garage, not all of them
        int found = -1;
        for(int i{0}; i < capacity_; i++){
            if(arr_[i] == to_remove){
                found = i;
                break;
            }
            if(found != -1) {std::cout<<"broke\n";break;} //break out of for loop after finding first instance of vehicle to_remove
        }
        //remove the vehicle
        int space = to_remove.getSpaces();
        Vehicle tmp{};
        for(int i{found}; i < found + space; ++i){
            arr_[i] = tmp;
            arr_[i].setGarageSpaces(tmp.getGaragePositions());
            arr_[i].setNumWheels(tmp.getNumWheels());
        }
        num_vehicles_ -= space;
        arrange();
        return true;
    }   
}

bool Garage::isFull() const{
    return (num_vehicles_ >= capacity_);
}

bool Garage::swapVehicles(Vehicle swap_in, Vehicle swap_out){
    // if(removeVehicle(swap_out)){
    //     return addVehicle(swap_in);
    // }
    return (removeVehicle(swap_out) && addVehicle(swap_in));
}

void Garage::display() const{
    //if there is a change in vehicle type in sequential garage space, arr_, then output
    /**
     * BECAUSE arrange() is ambiguous, I created a condition for when the Vehicle array is empty at the beginning,
     * versus when it is empty at the end, i.e. has vehicles at the back vs having vehicles at the front
    */
    if(arr_[0] == Vehicle()){
        for(int i{0}; i < capacity_-1; ++i){
            if(arr_[i + 1] != arr_[i]){
                std::cout << "i counter:" << i << std::endl;
                std::cout << "Name:" << arr_[i + 1].getName() << " Manufacturer:" << arr_[i + 1].getManufacturer() << "\n\n";
            }
    }
    }else{
        for(int i{0}; i < capacity_-1; ++i){
            if(arr_[i + 1] != arr_[i]){
                std::cout << "i counter:" << i << std::endl;
                std::cout << "Name:" << arr_[i].getName() << " Manufacturer:" << arr_[i].getManufacturer() << "\n\n";
            }
        }
        //edge case for if last item in arr_ is a motorcycle
        if(arr_[capacity_] != Vehicle()){
            std::cout << "Name:" << arr_[capacity_].getName() << " Manufacturer:" << arr_[capacity_].getManufacturer() << "\n\n";
        }
    }
    
}
