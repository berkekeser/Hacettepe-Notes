#include <iostream>
#include <fstream>
#include <string>
#include "GameFunctions.h"
#include "FileOperations.h"

using namespace std;

// global variable for file writing
ofstream outputFile;

int main(int argc, char* argv[]) {

    outputFile.open (argv[3]);
    FileOperations readFile;
    readFile.readDeckFile(argv[1]);
    GameFunctions gameStart;

    fillOpenDeck(gameStart, readFile.startDeck);
    copyStockToGameObject(gameStart, readFile.startDeck);
    fillTableu(gameStart, readFile.startDeck);
    readFile.readCommandsFile(argv[2], gameStart, readFile);

    outputFile.close();
    return 0;
}


