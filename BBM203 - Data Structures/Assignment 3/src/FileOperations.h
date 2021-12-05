#ifndef ASSIGNMENT3_FILEOPERATIONS_H
#define ASSIGNMENT3_FILEOPERATIONS_H

#include <iostream>
#include <fstream>
#include <string.h>
#include "CargoSystem.h"

using namespace std;

class FileOperations {
public:
    void style_tokenizer(string inp, char* delim, CargoSystem &cargoSystem);
    void readDestinationFile(string name, CargoSystem &cargoSystem);
    void readPackageFile(string name, CargoSystem &cargoSystem);
    void readTruckFile(string name, CargoSystem &cargoSystem);
    void readMissionFile(string name, CargoSystem &cargoSystem);
};

#endif //ASSIGNMENT3_FILEOPERATIONS_H
