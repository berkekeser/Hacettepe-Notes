#include "FileOperations.h"
#include "BinaryTree.h"
#include <algorithm>
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

extern ofstream outputFile;

void FileOperations::readInputFile(string name) {

    ifstream inputFile;
    inputFile.open(name);

    // ifstream ignore whitespaces with this code its read as expected
    inputFile >> std::noskipws;

    if(!inputFile)
    {
        cout << name << " file does not exist" << endl;
        exit(1); // if file does not exist terminate
    }

    char character;
    string input = "";


    while(inputFile >> character)
    {
        input += character;
        charactersVector.push_back(character);
    }

    //calculate Frequency
    calculateFrequency(charactersVector,myMap);

    sortMap(myMap, sortedVector);

    vector<Tree*> treeVector;

    // Huffman Algorithm
    for(int i=0; i < sortedVector.size(); i++)
    {
        Tree *newTree = new Tree;
        newTree->character = sortedVector[i].first;
        newTree->weight = sortedVector[i].second;
        newTree->left = NULL;
        newTree->right = NULL;
        treeVector.push_back(newTree);
    }

    while (treeVector.size() != 1)
    {
        Tree *newTree = new Tree;
        newTree->weight = treeVector[0]->weight + treeVector[1]->weight;
        newTree->character = '.';
        newTree->left = treeVector[0];
        newTree->right = treeVector[1];
        treeVector.push_back(newTree);
        treeVector.erase(treeVector.begin());
        treeVector.erase(treeVector.begin());
        sort(treeVector.begin(), treeVector.end(), NodeComparison);
    }

    BinaryTree binaryTree;
    // print table
    binaryTree.printPaths(treeVector[0]);

    // print table of Huffman Decode
    ofstream decodeTable;
    decodeTable.open("decodeTable.txt");
    map<char, string>::iterator itr;
    cout << "Table For Encoding" << endl;
    cout << "\tKEY\tELEMENT" << endl;
    for (itr = binaryTree.encodingMap.begin(); itr != binaryTree.encodingMap.end(); ++itr) {
        // if its blankspace print ''
        if(itr->first == 32)
        {
            cout << '\t' << "''" << '\t' << itr->second << '\n';
            decodeTable << "''" << " " << itr->second << '\n';
        }
        else
        {
            cout << '\t' << itr->first << '\t' << itr->second << '\n';
            decodeTable << itr->first << " " << itr->second << endl;
        }

    }
    cout << endl;

    decodeTable.close();

    cout << "Given input:\n" << input << endl;
    cout << "Encoded(seperated with space for easy reading):\n";
    for(char& c : input) {
        cout << binaryTree.encodingMap[c] << " ";
    }
    cout << endl;

    binaryTree.printBinaryTree("", treeVector[0], false, true);

    // close file
    outputFile.close();
    inputFile.close();

}

bool FileOperations::NodeComparison(Tree *a, Tree *b) {
    return a->weight < b->weight;
}

void FileOperations::calculateFrequency(vector<char> vec, map<char, int> &M) {

    for (int i = 0; vec[i]; i++) {
        if (M.find(vec[i]) == M.end())
            M[vec[i]] = 1;
        else
            M[vec[i]]++;
    }
}

void FileOperations::sortMap(map<char, int> &M, vector<pair<char, int>> &A) {
    for (auto& it : M) {
        A.push_back(it);
    }
    // Sort map by using comparator function
    sort(A.begin(), A.end(), cmp);
}

bool FileOperations::cmp(const pair<char, int> &a, const pair<char, int> &b) {
    return a.second < b.second;
}

void FileOperations::readFile(string name) {

    ifstream inputFile;
    inputFile.open(name);

    if(!inputFile)
    {
        cout << name << " file does not exist" << endl;
        exit(1); // if file does not exist terminate
    }

    string line;
    while(getline(inputFile, line))
    {
        cout << line << endl;
    }

}

void FileOperations::returnHuffmanEncoding(string character) {

    ifstream inputFile;
    inputFile.open("decodeTable.txt");

    map<string, string> decodeMap;

    string line;
    while(inputFile >> line)
    {
        string letter;
        letter = line;
        string encode;
        inputFile >> line;
        encode = line;
        decodeMap.insert({ letter, encode });
    }

    if (decodeMap.count(character))
        cout << decodeMap[character] << endl;
    else
        cout << "given character: " << character << " does not exist in Huffman tree." << endl;

    inputFile.close();

}

void FileOperations::decodeHuffmanEncoding(string fileName) {

    ifstream inputFile;
    inputFile.open("decodeTable.txt");

    ifstream encodedFile;

    encodedFile.open(fileName);

    if(!encodedFile)
    {
        cout << "File does not exist: " << fileName << endl;
        exit(1); // if file does not exist terminate
    }


    map<string, string> decodeMap;

    string line;
    while(inputFile >> line)
    {
        string letter;
        letter = line;
        string encode;
        inputFile >> line;
        encode = line;
        decodeMap.insert({ encode, letter });
    }

    cout << "Decoded output:" << endl;

    char byte;
    string check = "";
    while(encodedFile >> byte)
    {
        check += byte;
        if (decodeMap.count(check))
        {
            cout << decodeMap[check];
            check = "";
        }
    }

    cout << endl;

    //close file
    inputFile.close();
    encodedFile.close();
}
