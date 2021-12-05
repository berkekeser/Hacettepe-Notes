//
// Created by Berke Keser on 6.12.2020.
//

#include "Package.h"

Package::~Package() {

}

Package::Package() {
}

Package::Package(string _packageName) {
    name = _packageName;
}

ostream &operator<<(ostream &stream, Package ob) {
    stream << ob.name;
    return stream;
}