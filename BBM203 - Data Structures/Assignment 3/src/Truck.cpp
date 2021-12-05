#include "Truck.h"

Truck::Truck() {
}


Truck::~Truck() {

}

Truck::Truck(string _truckName,float _powerOfTruck) {
    name = _truckName;
    powerOfTruck = _powerOfTruck;
}

ostream &operator<<(ostream &stream, Truck ob) {
    stream << ob.name;
    return stream;
}