//
// Created by Berke Keser on 6.12.2020.
//

#ifndef ASSIGNMENT3_PACKAGE_H
#define ASSIGNMENT3_PACKAGE_H

using namespace std;
#include "iostream"
#include <string.h>

class Package {
public:
    Package();
    Package(string _packageName);
    ~Package();
    string name;
    float powerOfTruck;
    friend ostream &operator<<(ostream &stream, Package ob);

};


#endif //ASSIGNMENT3_PACKAGE_H
