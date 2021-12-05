#include <iostream>
#include <list>
#include "FileOperations.h"

using namespace std;

ofstream outputFile;

int main(int argc, char* argv[]) {

    FileOperations readFile;

    if ( (string(argv[1]) == "-i") && (string(argv[3]) == "-encode"))
    {
        string outputFilename = "binaryTreeEncoding.txt";
        outputFile.open(outputFilename);
        readFile.readInputFile(argv[2]);

    }
    else if( (string(argv[1]) == "-i") && (string(argv[3]) == "-decode"))
    {
        ifstream checkFile;
        checkFile.open("decodeTable.txt");
        if(!checkFile)
        {
            cout << "You have to encode your file for performing this operation." << endl;
            exit(1); // if file does not exist terminate
        }
        else
        {
            readFile.decodeHuffmanEncoding(argv[2]);
        }
        checkFile.close();
    }
    else if(string(argv[1]) == "-s" )
    {

        ifstream checkFile;
        checkFile.open("decodeTable.txt");
        if(!checkFile)
        {
            cout << "You have to encode your file for performing this operation." << endl;
            exit(1); // if file does not exist terminate
        }
        else
        {
            readFile.returnHuffmanEncoding(argv[2]);
        }
        checkFile.close();
    }
    else if(string(argv[1]) == "-l" )
    {
        ifstream checkFile;
        checkFile.open("binaryTreeEncoding.txt");
        if(!checkFile)
        {
            cout << "You have to encode your file for performing this operation." << endl;
            exit(1); // if file does not exist terminate
        }
        else{
            cout << "list tree" << endl;
            FileOperations readTree;
            readTree.readFile("binaryTreeEncoding.txt");
        }
    }
    else
    {
        cout << "Invalid command line arguments." << endl;
    }

    return 0;
}