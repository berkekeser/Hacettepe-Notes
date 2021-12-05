#ifndef ASSIGNMENT3_TRUCK_H
#define ASSIGNMENT3_TRUCK_H

using namespace std;

#include <iostream>
#include <string.h>
#include "Package.h"

class Truck : public Package {
public:
    Truck();
    Truck(string _truckName, float _powerOfTruck);
    ~Truck();
    friend ostream &operator<<(ostream &stream, Truck ob);
};


#endif //ASSIGNMENT3_TRUCK_H
