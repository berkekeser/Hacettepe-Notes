#ifndef ASSIGNMENT3_CARGOSYSTEM_H
#define ASSIGNMENT3_CARGOSYSTEM_H

using namespace std;
#include "iostream"
#include <string.h>
#include "Stack.h"
#include "Package.h"
#include "Queue.h"
#include "Truck.h"
#include "GenericDoublyLinkedList.h"

class CargoSystem {
public:
    CargoSystem();
    ~CargoSystem();
    void addCity(string cityName);
    void addPackage(Package _package, string _cityName);
    void addTruck(string _truck, string _cityName, float _powerOfTruck);
    void missionOperation(string sStation, string mStation, string tStation, int n, int k, string indeces);
    void printResult();

private:
    struct CargoNode{
        string cityName;
        Stack<Package> package;
        Queue<Truck> station;
        CargoNode *next;
    };
    CargoNode *_headCargo;
    int _size;

    void
    firstPartOfTransfer(const string &startStation, int n, CargoNode *findStartCity, GenericDoublyLinkedList<Package> &transfer,
                        Truck &firstTruck) const;

    void
    secondPartMidwayOfTransfer(const string &midwayStation, int k, string indeces, GenericDoublyLinkedList<Package> &transfer,
                               CargoNode *findMidwayStation) const;

    void thirdPartOfTransfer(const string &targetStation, GenericDoublyLinkedList<Package> &transfer,
                             CargoNode *findTargetStation) const;
};

#endif //ASSIGNMENT3_CARGOSYSTEM_H
