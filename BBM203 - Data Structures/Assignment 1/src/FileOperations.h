#ifndef BBM201_ASSIGNMENT1_FILEOPERATIONS_H
#define BBM201_ASSIGNMENT1_FILEOPERATIONS_H

#include <iostream>
#include <fstream>
#include <string.h>
#include "GameFunctions.h"

using namespace std;

extern ofstream outputFile;

class FileOperations {

public:
    string startDeck[52];
    void readDeckFile(string name);
    void readCommandsFile(string name, GameFunctions game, FileOperations file);
    void style_tokenizer(string inp, char* delim, GameFunctions &game2, FileOperations file2);
};

#endif //BBM201_ASSIGNMENT1_FILEOPERATIONS_H
