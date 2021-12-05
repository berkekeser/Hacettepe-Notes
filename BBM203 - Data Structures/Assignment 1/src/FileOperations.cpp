#include <iostream>
#include <string.h>
#include <fstream>
#include "FileOperations.h"
#include "GameFunctions.h"

using namespace std;

extern ofstream outputFile;

void FileOperations::readDeckFile(string name)
{
    ifstream deckFile;
    deckFile.open(name);

    if(!deckFile)
    {
        cout << name << "file does not exist" << endl;
        exit(1); // if file does not exist terminate
    }

    string line;

    int counter2 =0;
    while(deckFile >> line)
    {
        startDeck[counter2] = line;
        counter2++;
    }
    deckFile.close();
}

void FileOperations::readCommandsFile(string name, GameFunctions game, FileOperations file)
{
    ifstream commandsFile;
    commandsFile.open(name);
    if(!commandsFile)
    {
        cout << name << "file does not exist" << endl;
        exit(1); // if file does not exist terminate
    }

    string line;

    while(getline(commandsFile, line))
    {
        if (game.check == false)
            printUpperPartCurrent(game);
        else
        {
            printUpperPartBefore(game);
        }
        displayGameBoard(game);
//        cout << line << endl << endl;
        outputFile << line << "\n\n";
        style_tokenizer(line, (char*) " ", game,file);

//        cout << "****************************************" << endl;
        outputFile << "****************************************\n";

//        cout << endl;
        outputFile << "\n";
        if (game.gameEnd == true)
        {
//            cout << "Game Over!" << endl;
            outputFile << "Game Over!\n";
        }

        if (winCheck(game))
        {
            printUpperPartCurrent(game);
//            cout << "****************************************" << endl;
            outputFile << "\n\n";
            outputFile << "****************************************\n";
//            cout << endl;
            outputFile << "\n";
//            cout << "You Win!" << endl;
            outputFile << "You Win!\n";
//            cout << endl;
            outputFile << "\n";
//            cout << "Game Over!" << endl;
            outputFile << "Game Over!\n";
        }

    }
    commandsFile.close();
}

void FileOperations::style_tokenizer(string inp, char* delim, GameFunctions &game2, FileOperations file2)
{

    const char* c_string = inp.c_str();

    char* token = strtok((char*)c_string, delim);

    while (token) {

        //move to foundation pile n
        if (strcmp(token, "move") == 0)
        {
            token = strtok(NULL, delim);
            // move waste
            if (strcmp(token, "waste") == 0 || strcmp(token, "waste\r") == 0)
            {
                token = strtok(NULL, delim);
                moveWaste(game2, atoi(token));
            }

            //move to
            if (strcmp(token, "to") == 0)
            {
                token = strtok(NULL, delim);
                if (strcmp(token, "foundation") == 0)
                {
                    token = strtok(NULL, delim);
                    if (strcmp(token, "pile") == 0)
                    {
                        token = strtok(NULL, delim);
                        moveToFoundationNumber(atoi(token), game2);
                    }
                    // move to foundation waste
                    if (strcmp(token, "waste") == 0 || strcmp(token, "waste\r") == 0)
                    {
                        moveToFoundationWaste(game2);

                    }
                }
            }

            // move pile
            if (strcmp(token, "pile") == 0)
            {
                token = strtok(NULL, delim);
                int firstNumber = atoi(token);
                token = strtok(NULL, delim);
                int secondNumber = atoi(token);
                token = strtok(NULL, delim);
                int thirdNumber = atoi(token);
                movePile(game2, firstNumber, secondNumber, thirdNumber);
            }
        }
        // open n & open from stock
        if (strcmp(token, "open") == 0) {
            token = strtok(NULL, delim);
            if (strcmp(token, "from") == 0)
            {
                token = strtok(NULL, delim);
                if (strcmp(token, "stock") == 0 || strcmp(token, "stock\r") == 0 )
                {
                    openFromStock(game2);
                }
            }
            else
            {
                openCard(atoi(token), game2);
            }
        }

        // exit
        if (strcmp(token, "exit") == 0 || strcmp(token, "exit\r") == 0) {
            game2.gameEnd = true;
        }
        token = strtok(NULL, delim);
    }
}