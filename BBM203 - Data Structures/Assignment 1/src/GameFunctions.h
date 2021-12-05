#ifndef BBM201_ASSIGNMENT1_GAMEFUNCTIONS_H
#define BBM201_ASSIGNMENT1_GAMEFUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

extern ofstream outputFile;

class GameFunctions {

public:
    string fill = "   ";
    string tableMatrix[12][7] = {
               /*  initializers for row indexed by 0 */
            {fill, "@@@", "@@@","@@@","@@@","@@@","@@@"},
            {fill, fill , "@@@","@@@","@@@","@@@","@@@"},
            {fill, fill , fill, "@@@","@@@","@@@","@@@"},
            {fill, fill , fill, fill, "@@@","@@@","@@@"},
            {fill, fill , fill, fill, fill ,"@@@","@@@"},
            {fill, fill , fill, fill, fill ,fill ,"@@@"},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
    };
    string open[20][7] = {
            /*  initializers for row indexed by 0 */
            {fill, "@@@", "@@@","@@@","@@@","@@@","@@@"},
            {fill, fill , "@@@","@@@","@@@","@@@","@@@"},
            {fill, fill , fill, "@@@","@@@","@@@","@@@"},
            {fill, fill , fill, fill, "@@@","@@@","@@@"},
            {fill, fill , fill, fill, fill ,"@@@","@@@"},
            {fill, fill , fill, fill, fill ,fill ,"@@@"},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
            {fill, fill , fill, fill, fill ,fill ,fill},
    };
    string stock2[9][3];
    int headCounter = 0;
    int tailCounter = 9;
    bool check = false;
    bool gameEnd = false;
    string tempStock[3];
    string foundationArea[4] = {"___", "___", "___", "___"};

};


void printUpperPartCurrent(GameFunctions &game);
void printUpperPartBefore(GameFunctions &game);
void copyStockToGameObject(GameFunctions &game, string *deck);
void moveToFoundationNumber(int number, GameFunctions &game);
void displayGameBoard(GameFunctions &display);
void openCard(int openIndex, GameFunctions &game);
void fillOpenDeck(GameFunctions &game, string *deck);
void fillTableu(GameFunctions &game, string *deck);
void movePile(GameFunctions &game, int num1, int num2, int num3);
int findInsertLocation(GameFunctions &game, int findIndex);
void openFromStock(GameFunctions &game);
void moveWaste(GameFunctions &game, int number);
void moveToFoundationWaste(GameFunctions &game);
void sortStockElements(GameFunctions &game);
bool suitabilityCheck(string card1, string card2);
bool suitabilityCheckTwo(GameFunctions &game, string card1, string card2, int targetIndex, int number);
bool winCheck(GameFunctions &game);

#endif //BBM201_ASSIGNMENT1_GAMEFUNCTIONS_H
