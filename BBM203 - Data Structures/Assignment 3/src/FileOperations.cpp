using namespace std;
#include "FileOperations.h"
#include "string.h"
#include "iostream"


void FileOperations::style_tokenizer(string inp, char* delim, CargoSystem &cargoSystem) {

    const char *c_string = inp.c_str();

    char *token = strtok((char *) c_string, delim);

    while(token)
    {

        string sStation = token;
        token = strtok(NULL, delim);

        string mStation = token;
        token = strtok(NULL, delim);

        string tStation = token;
        token = strtok(NULL, delim);

        int nFromStartStation = atoi(token);
        token = strtok(NULL, delim);

        int nDropMidwayStation = atoi(token);
        token = strtok(NULL, delim);

        string indices = token;

        cargoSystem.missionOperation(sStation, mStation,tStation, nFromStartStation, nDropMidwayStation, indices);
        token = strtok(NULL, delim);
    }
}

void FileOperations::readDestinationFile(string name, CargoSystem &cargoSystem) {

    ifstream destsFile;
    destsFile.open(name);

    if(!destsFile)
    {
        cout << name << "file does not exist" << endl;
        exit(1); // if file does not exist terminate
    }

    string line;

    while(destsFile >> line)
    {
        cargoSystem.addCity(line);
    }
    destsFile.close();
}

void FileOperations::readPackageFile(string name, CargoSystem &cargoSystem) {

    ifstream packageFile;
    packageFile.open(name);

    if(!packageFile)
    {
        cout << name << "file does not exist" << endl;
        exit(1); // if file does not exist terminate
    }

    string line;

    while(packageFile >> line)
    {
        string packageName = line;
        packageFile >> line;
        string cityName = line;
        cargoSystem.addPackage(packageName, cityName);
    }
    packageFile.close();
}

void FileOperations::readTruckFile(string name, CargoSystem &cargoSystem) {

    ifstream truckFile;
    truckFile.open(name);

    if(!truckFile)
    {
        cout << name << "file does not exist" << endl;
        exit(1); // if file does not exist terminate
    }

    string line;

    while(truckFile >> line)
    {
        string truckNumber = line;
        truckFile >> line;
        string cityName = line;
        truckFile >> line;
        float powerOfTruck = stof(line);
        cargoSystem.addTruck(truckNumber,cityName, powerOfTruck);
    }

    truckFile.close();

}

void FileOperations::readMissionFile(string name, CargoSystem &cargoSystem) {

    ifstream missionFile;
    missionFile.open(name);

    if(!missionFile)
    {
        cout << name << "file does not exist" << endl;
        exit(1); // if file does not exist terminate
    }

    string line;

    while(getline(missionFile, line))
    {
        style_tokenizer(line, (char*) "-", cargoSystem);
    }

    missionFile.close();

}
