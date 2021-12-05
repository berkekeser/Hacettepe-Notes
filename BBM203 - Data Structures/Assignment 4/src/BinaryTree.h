#ifndef BBM201_ASSIGNMENT4_BINARYTREE_H
#define BBM201_ASSIGNMENT4_BINARYTREE_H

#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string.h>
#include <fstream>

using namespace std;
extern ofstream outputFile;

struct Tree
{
    int weight;
    char character;
    Tree *left;
    Tree *right;
};

class BinaryTree {
public:
    bool flag2 = true;
    bool flag3 = false;
    map<char, string> encodingMap;
    void printPaths(Tree *node);
    void printPathsRecursively(Tree *node, string &path, int lengthOfPath);
    void createEncodingMap(char leafCharacter, string &chars, int length);
    void printBinaryTree(const string &marginFromLeft, const Tree *treeNode, bool isLeft, bool isRoot);
};

#endif //BBM201_ASSIGNMENT4_BINARYTREE_H
