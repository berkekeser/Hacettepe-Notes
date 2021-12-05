using namespace std;

#include "CargoSystem.h"
#include "Package.h"
#include "Truck.h"
#include "GenericDoublyLinkedList.h"
#include <string>
#include <sstream>


CargoSystem::CargoSystem() {
    _headCargo = NULL;
}

CargoSystem::~CargoSystem() {

}

void CargoSystem::addCity(string cityName) {

    CargoNode *temp = _headCargo;
    if(temp == NULL)
    {
        _headCargo = new CargoNode;
        _headCargo->cityName = cityName;
        _headCargo->next = NULL;
    }
    else
    {
        CargoNode *newNode = new CargoNode;
        newNode->cityName = cityName;
        newNode->next = NULL;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    _size++;
}

void CargoSystem::printResult() {
    CargoNode *temp = _headCargo;

    while (temp->next != NULL)
    {
        cout << temp->cityName << endl;
        cout << "Packages:" << endl;
        temp->package.print();

        cout << "Trucks:" << endl;
        temp->station.print();
        cout << "-------------" << endl;
        temp = temp->next;
    }
    // for last node
    cout << temp->cityName << endl;
    cout << "Packages:" << endl;
    temp->package.print();

    cout << "Trucks:" << endl;
    temp->station.print();
    cout << "-------------" << endl;
}

void CargoSystem::addPackage(Package _package, string _cityName) {
    CargoNode *temp = _headCargo;
    Package tempPackage(_package);
    while (temp->next != NULL)
    {
        if (temp->cityName == _cityName)
        {
            temp->package.push(tempPackage);
        }
        temp = temp->next;
    }

    // for last node
    if (temp->cityName == _cityName)
        temp->package.push(tempPackage);
}

void CargoSystem::addTruck(string _truck, string _cityName, float _powerOfTruck) {
    CargoNode *temp = _headCargo;
    Truck tempTruck(_truck, _powerOfTruck);
    while (temp->next != NULL)
    {
        if (temp->cityName == _cityName)
        {
            temp->station.enqueue(tempTruck);
        }
        temp = temp->next;
    }
    // for last node
    if (temp->cityName == _cityName)
        temp->station.enqueue(tempTruck);
}

void CargoSystem::missionOperation(string startStation, string midwayStation, string targetStation, int n, int k,
                                   string indeces) {

    /* Mission operation separated to tree part.
     * First part: getting truck and packages from matched city
     * Second part: dropping packages in the midway station
     * Third part: truck reaches the target station and drop all packages.
     */

    CargoNode *findStartCity = _headCargo;

    GenericDoublyLinkedList<Package> transfer;

    Truck firstTruck;

    // get truck and packages from matched city
    firstPartOfTransfer(startStation, n, findStartCity, transfer, firstTruck);

    // drop package in Midway Station

    CargoNode *findMidwayStation = _headCargo;
    secondPartMidwayOfTransfer(midwayStation, k, indeces, transfer, findMidwayStation);

    //targetStation
    CargoNode *findTargetStation = _headCargo;
    thirdPartOfTransfer(targetStation, transfer, findTargetStation);

}

void CargoSystem::thirdPartOfTransfer(const string &targetStation, GenericDoublyLinkedList<Package> &transfer,
                                      CargoSystem::CargoNode *findTargetStation) const {


    do {
        if(findTargetStation->cityName == targetStation)
        {
            while (transfer.checkSize())
            {
                DoubleNode<Package> *matchedTargetPackage =  transfer.getElementNthPosition(1);
                Package packageFromTransfer(matchedTargetPackage->data);
                findTargetStation->package.push(packageFromTransfer);
                transfer.deleteFromNthPosition(1);
            }
            DoubleNode<Package> *matchedTruck =  transfer.getElementNthPosition(0);
            Truck tempTruck(matchedTruck->data.name , matchedTruck->data.powerOfTruck);
            findTargetStation->station.enqueue(tempTruck);
            transfer.deleteFromNthPosition(0);
        }
        findTargetStation = findTargetStation->next;
    } while (findTargetStation->next != NULL);

    // for last node
    if(findTargetStation->cityName == targetStation)
    {
        while (transfer.checkSize())
        {
            DoubleNode<Package> *matchedTargetPackage =  transfer.getElementNthPosition(1);
            Package packageFromTransfer(matchedTargetPackage->data);
            findTargetStation->package.push(packageFromTransfer);
            transfer.deleteFromNthPosition(1);
        }
        DoubleNode<Package> *matchedTruck =  transfer.getElementNthPosition(0);
        Truck tempTruck(matchedTruck->data.name , matchedTruck->data.powerOfTruck);
        findTargetStation->station.enqueue(tempTruck);
        transfer.deleteFromNthPosition(0);
    }

}

void CargoSystem::secondPartMidwayOfTransfer(const string &midwayStation, int k, string indeces,
                                             GenericDoublyLinkedList<Package> &transfer,
                                             CargoSystem::CargoNode *findMidwayStation) const {

        /* This function find matching city at the beginning.
         * After finding, its operates package and truck operation
         * by using stack and queue implementation.
         * Its tokenize given string indeces without removing comma.
         * Take packages from top and add truck.
         * Than it's removing from city's package hub.
         * At the end it remove packages from the transfer truck.
         */

        do {
            if(findMidwayStation->cityName == midwayStation)
            {
                while(k > 0)
                {
                    Package tempPackage;
                    findMidwayStation->package.getTop(tempPackage);
                    transfer.add(tempPackage);
                    findMidwayStation->package.pop();;
                    k--;
                }

                // tokenize string by "," without deleting comma
                string text(indeces);
                stringstream textstr(text);
                string line;
                vector<std::string> data;
                while(getline(textstr,line,','))
                {
                    int num;
                    stringstream ss;
                    ss << line;
                    ss >> num;
                    DoubleNode<Package> *matchedPackage =  transfer.getElementNthPosition(num+1);
                    Package packageFromTransfer(matchedPackage->data);
                    findMidwayStation->package.push(packageFromTransfer);
                    data.push_back(line);
                }

            }
            findMidwayStation = findMidwayStation->next;
        } while (findMidwayStation->next != NULL);

    // for last node
    if(findMidwayStation->cityName == midwayStation)
    {
        while(k > 0)
        {
            Package tempPackage;
            findMidwayStation->package.getTop(tempPackage);
            transfer.add(tempPackage);
            findMidwayStation->package.pop();;
            k--;
        }

        // tokenize string by "," without deleting comma
        string text(indeces);
        stringstream textstr(text);
        string line;
        vector<std::string> data;
        while(getline(textstr,line,','))
        {
            int num;
            stringstream ss;
            ss << line;
            ss >> num;
            DoubleNode<Package> *matchedPackage =  transfer.getElementNthPosition(num+1);
            Package packageFromTransfer(matchedPackage->data);
            findMidwayStation->package.push(packageFromTransfer);
            data.push_back(line);
        }
    }

    // delete elements according to given indexes
    transfer.deleteByGivenIndeces(indeces, transfer);

}

void CargoSystem::firstPartOfTransfer(const string &startStation, int n, CargoSystem::CargoNode *findStartCity,
                                      GenericDoublyLinkedList<Package> &transfer, Truck &firstTruck) const {

    /* This function find matching city at the beginning.
     * After finding, its operates package and truck operation
     * by using stack and queue implementation.
     */
    do{
        if (findStartCity->cityName == startStation)
        {
            findStartCity->station.getFront(firstTruck);
            transfer.add(firstTruck);

            while(n > 0)
            {
                Package tempPackage;
                findStartCity->package.getTop(tempPackage);
                transfer.add(tempPackage);
                findStartCity->package.pop();
                n--;
            }
            findStartCity->station.dequeue();
        }
        findStartCity = findStartCity->next;
    } while (findStartCity->next != NULL);

    // for last node
    if (findStartCity->cityName == startStation)
    {
        findStartCity->station.getFront(firstTruck);
        transfer.add(firstTruck);

        while(n > 0)
        {
            Package tempPackage;
            findStartCity->package.getTop(tempPackage);
            transfer.add(tempPackage);
            findStartCity->package.pop();
            n--;
        }
        findStartCity->station.dequeue();
    }

}

