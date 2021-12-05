#ifndef BBM201_ASSIGNMENT4_FILEOPERATIONS_H
#define BBM201_ASSIGNMENT4_FILEOPERATIONS_H

#include "BinaryTree.h"
#include <algorithm>
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

extern ofstream outputFile;

class FileOperations {
public:
    vector<char> charactersVector;
    vector<pair<char, int> > sortedVector;
    map<char, int> myMap;
    void readInputFile(string name);
    void readFile(string name);
    void returnHuffmanEncoding(string name);
    void calculateFrequency(vector<char> vec, map<char, int> &M);
    void decodeHuffmanEncoding(string fileName);
    void sortMap(map<char, int>& M, vector<pair<char, int> > &A);
    static bool cmp(const pair<char, int>& a, const pair<char, int>& b);
    static bool NodeComparison(Tree *a, Tree *b);
};


#endif //BBM201_ASSIGNMENT4_FILEOPERATIONS_H
