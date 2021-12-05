#include "BinaryTree.h"
#include <iostream>
#include <map>

using namespace std;

extern ofstream outputFile;

void BinaryTree::printPaths(Tree *node) {
    string path;
    printPathsRecursively(node, path, 0);
}

void BinaryTree::printPathsRecursively(Tree *node, string &path, int lengthOfPath) {

    if (node == NULL)
        return;

    if (flag3)
    {
        if (flag2)
            path[lengthOfPath++] = '0';
        else
            path[lengthOfPath++] = '1';
    }
    flag3 = true;

    // when function reach the leaf. It will print path
    if (node->left == NULL && node->right == NULL)
    {
        createEncodingMap(node->character, path, lengthOfPath);
    }
    else
    {
        flag2 = true;
        printPathsRecursively(node->left, path, lengthOfPath);
        flag2 = false;
        printPathsRecursively(node->right, path, lengthOfPath);
    }
}

void BinaryTree::createEncodingMap(char leafCharacter, string &chars, int length) {
    int i;
    string addBits = "";
    for (i = 0; i < length; i++)
    {
        addBits += chars[i];
    }

    encodingMap.insert(pair<char, string>(leafCharacter, addBits));
}

void BinaryTree::printBinaryTree(const string& marginFromLeft, const Tree* treeNode, bool isLeft, bool isRoot)
{
    if( treeNode != NULL )
    {
        // Its gives margin from left.
        outputFile << marginFromLeft;

        if(isRoot)
        {
            outputFile << "├─ root─> ";
            isRoot = false;
        }
        else
        {
            if(isLeft)
            {
                if(treeNode->left == NULL && treeNode->right == NULL)
                    outputFile << "├─ left leaf─> ";
                else
                    outputFile << "├─ left child ─> ";
            }
            else // is Right
            {
                if(treeNode->left == NULL && treeNode->right == NULL)
                    outputFile << "└─ right leaf─> ";
                else
                    outputFile << "└─ right child > ";
            }
        }

        // print the value of the node
        if(treeNode->character == 32) //32 represents empty space in ASCII
            outputFile << "''" << endl;
        else
            outputFile << treeNode->character << endl;

        //Recursive Call
        printBinaryTree(marginFromLeft + (isLeft ? "│   " : "    "), treeNode->left, true, isRoot);
        printBinaryTree(marginFromLeft + (isLeft ? "│   " : "    "), treeNode->right, false, isRoot);
    }
}