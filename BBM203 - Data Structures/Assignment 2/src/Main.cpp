#include <iostream>
#include "FileOperations.h"
#include "LibrarySystem.h"
#include "GenericSinglyLinkedList.h"
#include "GenericDoublyLinkedList.h"

using namespace std;

ofstream outputFile;

int main(int argc, char* argv[]) {

    freopen(argv[2],"w",stdout);

    FileOperations readFile;
    LibrarySystem newLibrary;
    readFile.readCommandsFile(argv[1] , newLibrary);

    fclose(stdout);

    return 0;
}
