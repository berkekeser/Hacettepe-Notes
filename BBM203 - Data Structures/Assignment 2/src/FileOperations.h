#ifndef BBM201_ASSIGNMENT2_FILEOPERATIONS_H
#define BBM201_ASSIGNMENT2_FILEOPERATIONS_H

#include <iostream>
#include <fstream>
#include <string.h>
#include "LibrarySystem.h"

using namespace std;


class FileOperations {

public:
    void style_tokenizer(string inp, char* delim, LibrarySystem &library2);
    void readCommandsFile(string name, LibrarySystem library);
};


#endif //BBM201_ASSIGNMENT2_FILEOPERATIONS_H
