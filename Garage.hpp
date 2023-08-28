#ifndef _GARAGE
#define _GARAGE
#include "Vehicle.hpp"

class Garage{
private:
/**
   Changes the contents of arr_ to have all non-null vehicles strictly at the end of the array and all inserted vehicles at the beginning of the array. HINT: create a new array and repoint arr_; don't do this "in-place"
*/
void arrange();

/* a pointer to an array of vehicles - HINT: dynamically allocate the actual array */
Vehicle *arr_;

/* the number of vehicle slots in the caller */
size_t capacity_;

/* the number of occupied vehicle slots in the caller */
size_t num_vehicles_;

public:
/* Parameterized constructor with a default argument for capacity of 12 */
Garage(size_t capacity = 12);

/**
   Inserts @param to_add into the number of spaces that correspond to its type
   into arr_[]; must insert from front to back

   As an example, if we had a garage that already contains an Audio R8 (a car)
   the default garage would have an Audio R8 object in both its first and second indeces.

   MUST INCREMENT num_vehicles_
   MUST RETURN FALSE IF isFull()
   MUST RETURN FALSE IF num_vehicles_ + to_add.getSpaces() > capacity_
 */
bool addVehicle(Vehicle to_add);

/**
  Replaces any object in arr_ that == @param to_remove with null::v

  MUST RETURN FALSE IF num_vehicles_ == 0
  MUST DECREMENT num_vehicles_
  MUST CALL arrange() immediately before return statement
*/
bool removeVehicle(Vehicle to_remove);

/**
  HINT: use what you already have!
*/
bool swapVehicles(Vehicle swap_in, Vehicle swap_out);

bool isFull() const;

/**
 * @note capacity should be >= 1
  Outputs the contents of the caller such that the manufacturer and vehicle name are only printed once per vehicle in arr_; for example if a garage object contains the aforementioned
  Audi R8 a call to display() will print

  Audi R8

  even though arr_ contains the vehicle in two positions - also print each vehicle on its own line
  
*/
void display() const;
};
#endif