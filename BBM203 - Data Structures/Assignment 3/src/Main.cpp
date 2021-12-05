#include "FileOperations.h"
#include <iostream>
#include "CargoSystem.h"

using namespace std;

int main(int argc, char* argv[]) {

    // take 5th argument as a file name and print result inside
    freopen(argv[5],"w",stdout);

    FileOperations readFile;
    CargoSystem newCargoSystem;

    // Read File and complete initialize statement
    readFile.readDestinationFile(argv[1], newCargoSystem);
    readFile.readPackageFile(argv[2], newCargoSystem);
    readFile.readTruckFile(argv[3], newCargoSystem);

    // Read Mission File and do transfer operation
    readFile.readMissionFile(argv[4], newCargoSystem);

    // Print out results
    newCargoSystem.printResult();

    fclose(stdout);

    return 0;
}
