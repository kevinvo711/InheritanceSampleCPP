#include "Vehicle.hpp"
#include "Car.hpp"
#include "Motorcycle.hpp"
#include "Bus.hpp"
#include "Garage.hpp"

// #include "Vehicle.cpp"
// #include "Car.cpp"

#include <iostream>

using std::cout, std::endl, std::cin;
int main(){
    Car myCar{"taxi", "tyota", 140, 3000, 35};
    cout << myCar.getName() << endl;
    cout << myCar.getNumWheels() << " wheels" << endl;
    cout << myCar.getSpaces() <<  " spaces" << endl;

    Bus school("ron", "hudson", 100, 8000, 15, 50);
    cout << school.getName() << endl;
    cout << school.getNumWheels() << " wheels" << endl;
    cout << school.getNumSeats() << " seats" << endl;
    cout << school.getSpaces() <<  " spaces" << endl;

    // int myArray[] {1,2,3,4,5};
    // int* p {myArray};
    // cout << p[1] << endl;
    // cout << myArray << endl;

    Vehicle* aList {new Vehicle[10]{}};
    Vehicle* bList = new Vehicle[3];
    aList[2] = school;
    aList[5] = myCar;

    Vehicle* aThing = new Vehicle();
    aThing->getName();

    Vehicle bThing;
    Vehicle* p = &bThing;

    Garage myGarage(8);
    myGarage.addVehicle(school);
    cout << "1 ";
    myGarage.display();
    myGarage.addVehicle(myCar);
    cout << "2 ";
    myGarage.display();
    myGarage.removeVehicle(school);
    cout << "3 ";
    myGarage.display();
    cout << "end \n";
    // myGarage.add

    // cout << "length\n";
    // int length;
    // cin >> length;
    // int* aaron{ new int[length]{} };
    // Vehicle* stuff { new Vehicle[length]};
    // for(int i{0}; i<length; ++i){
    //     cout << aaron[length] << " " << aaron + i << endl;
    //     cout << stuff[length].getName() << " " << stuff + i << endl;
    // }
    
    /*
    primeGenerator(int x, int y){
        for(int i = x; i < y; i++){
            bool prime = true
            for(int j = 2; j * j <= i; j++){
                for(i % j != 0){
                    prime = false; 
                    break;
                }
            }
        }
        if(prime == true){
            std::cout << i << " ";
        }
    }
    */
    
    return 0;
}