#include <iostream>
#include <fstream>
#include <string>
#include "GameFunctions.h"

void displayGameBoard(GameFunctions &display) {
    int counter = 0;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if(display.open[i][j] == "   ")
                counter++;
//            cout << display.open[i][j] << "   ";
            outputFile << display.open[i][j] << "   ";

        }
//        cout << endl;
        outputFile << "\n";
        if (counter == 7)
            break;
        counter = 0;
    }
}

void moveToFoundationNumber(int number, GameFunctions &game)
{
    int index = findInsertLocation(game,number);

    if (index == -1)
    {
//        cout << "Invalid Move!" << endl;
        outputFile << "Invalid Move!\n";
        return;
    }

    if(game.open[index][number] != "@@@" || game.open[index][number] != "   ")
    {
        string cardName = game.open[index][number];

        if (cardName[0] == 'H')
        {
            string card2 = game.foundationArea[0];
            int card1Number = stoi(cardName.substr (1,2));

            if(game.foundationArea[0] == "___" && card1Number == 1)
            {
                game.foundationArea[0] = cardName;
                game.open[index][number] = "   ";
                return;
            }

            bool check = suitabilityCheck(cardName, card2);
            if(check)
            {
                game.foundationArea[0] = cardName;
                game.open[index][number] = "   ";
            }
            else
            {
//                cout << "Invalid Move!" << endl;
                outputFile << "Invalid Move!\n";
                return;
            }
        }

        if (cardName[0] == 'D')
        {
            string card2 = game.foundationArea[1];
            int card1Number = stoi(cardName.substr (1,2));

            if(game.foundationArea[1] == "___" && card1Number == 1)
            {
                game.foundationArea[1] = cardName;
                game.open[index][number] = "   ";
                return;
            }

            bool check = suitabilityCheck(cardName, card2);
            if(check)
            {
                game.foundationArea[1] = cardName;
                game.open[index][number] = "   ";
            }
            else
            {
//                cout << "Invalid Move!" << endl;
                outputFile << "Invalid Move!\n";
                return;
            }
        }
        if (cardName[0] == 'S')
        {
            string card2 = game.foundationArea[2];
            int card1Number = stoi(cardName.substr (1,2));

            if(game.foundationArea[2] == "___" && card1Number == 1)
            {
                game.foundationArea[2] = cardName;
                game.open[index][number] = "   ";
                return;
            }

            bool check = suitabilityCheck(cardName, card2);
            if(check)
            {
                game.foundationArea[2] = cardName;
                game.open[index][number] = "   ";
            }
            else
            {
//                cout << "Invalid Move!" << endl;
                outputFile << "Invalid Move!\n";
                return;
            }
        }
        if (cardName[0] == 'C')
        {
            string card2 = game.foundationArea[3];
            int card1Number = stoi(cardName.substr (1,2));

            if(game.foundationArea[3] == "___" && card1Number == 1)
            {
                game.foundationArea[3] = cardName;
                game.open[index][number] = "   ";
                return;
            }

            bool check = suitabilityCheck(cardName, card2);
            if(check)
            {
                game.foundationArea[3] = cardName;
                game.open[index][number] = "   ";
            }
            else
            {
//                cout << "Invalid Move!" << endl;
                outputFile << "Invalid Move!\n";
                return;
            }
        }
    }
    else
    {
//        cout << "Invalid Move!" << endl;
        outputFile << "Invalid Move!\n";
    }
}

void movePile(GameFunctions &game, int num1, int num2, int num3)
{

    int index = findInsertLocation(game, num1);
    int index2 = findInsertLocation(game, num3);
    int counter = num2;

    for(int i = 0; i <= num2; i++)
    {
        string card1 = game.open[index-counter][num1];
        string card2 = game.open[index2][num3];

        if (index == -1)
        {
//            cout << "Invalid Move1!" << endl;
            outputFile << "Invalid Move!\n";
            return;
        }
        if (card1 != "   " && card2 != "   " && card2 != "@@@" && card1 != "@@@")
        {
            int cardNumber1 = stoi(card1.substr (1,2));
            int cardNumber2 = stoi(card2.substr (1,2));

            if (cardNumber2-cardNumber1 != 1)
            {
//                cout << "Invalid Move!" << endl;
                outputFile << "Invalid Move!\n";
                return;
            }
        }
        else if (card2 == "   ")
        {
            int cardNumber1 = stoi(card1.substr (1,2));
            if (cardNumber1 == 13)
            {
                game.open[index2+1][num3] = game.open[index-num2][num1];
                game.open[index-num2][num1] = "   ";
                index2++;
                index++;
            }
            else
            {
//                cout << "Invalid Move!" << endl;
                outputFile << "Invalid Move!\n";
                return;
            }
        }
        else
        {
//            cout << "Invalid Move!" << endl;
            outputFile << "Invalid Move!\n";
            return;
        }

        game.open[index2+1][num3] = game.open[index-num2][num1];
        game.open[index-num2][num1] = "   ";
        index2++;
        index++;
    }
}

void fillTableu(GameFunctions &game, string *deck)
{
    int row = 0;
    int col = 0;
    int check = 7;

    for (int i = 51; i >= 0; i--)
    {
        game.tableMatrix[row][col] = deck[i];
        if (col < check)
            col++;
        if (col == check && col != 6)
        {
            col = row + 1;
            row++;
        }
    }
}

int findInsertLocation(GameFunctions &game, int findIndex)
{
    int index = -1;

    for (int tableuIndex = 0; tableuIndex < 20; tableuIndex++) {
        if(game.open[tableuIndex][findIndex] != "   " || game.open[tableuIndex][findIndex] == "@@@")
            index++;
        else
            break;
    }
    return index; // for empty location
}

bool suitabilityCheck(string card1, string card2)
{
    int cardNumber1 = 0;
    int cardNumber2 = 0;


    if(card1 != "___")
    {
        cardNumber1 = stoi(card1.substr(1, 2));
    }

    if(card2 != "___")
    {
        cardNumber2 = stoi(card2.substr(1, 2));
    }

    if (cardNumber2 == 1 && card2 == "___")
        return true;

    if (cardNumber1 - cardNumber2 == 1)
        return true;

    return false;
}

void moveToFoundationWaste(GameFunctions &game)
{
    int counter = -1;
    for (int i = 0; i < 3; ++i) {
        if(game.stock2[game.headCounter][i] != "___")
            counter++;
    }

    string card1 = game.stock2[game.headCounter][counter];
    string card2;

    if (card1[0] == 'H')
    {
        card2 = game.foundationArea[0];
        bool check = suitabilityCheck(card1, card2);
        if (check)
        {
            game.foundationArea[0] = card1;
            game.stock2[game.headCounter][counter] = "___";
        }
        else
        {
//            cout << "Invalid Move!" << endl;
            outputFile << "Invalid Move!\n";
        }
    }

    if (card1[0] == 'D')
    {
        card2 = game.foundationArea[1];
        bool check = suitabilityCheck(card1, card2);
        if (check)
        {
            game.foundationArea[1] = card1;
            game.stock2[game.headCounter][counter] = "___";
        }
        else
        {
//            cout << "Invalid Move!" << endl;
            outputFile << "Invalid Move!\n";
        }
    }

    if (card1[0] == 'S')
    {
        card2 = game.foundationArea[2];
        bool check = suitabilityCheck(card1, card2);
        if (check)
        {
            game.foundationArea[2] = card1;
            game.stock2[game.headCounter][counter] = "___";
        }
        else
        {
//            cout << "Invalid Move!" << endl;
            outputFile << "Invalid Move!\n";
        }
    }

    if (card1[0] == 'C')
    {
        card2 = game.foundationArea[3];
        bool check = suitabilityCheck(card1, card2);
        if (check)
        {
            game.foundationArea[3] = card1;
            game.stock2[game.headCounter][counter] = "___";
        }
        else
        {
//            cout << "Invalid Move!" << endl;
            outputFile << "Invalid Move!\n";
        }
    }
}

bool suitabilityCheckTwo(GameFunctions &game, string card1, string card2, int targetIndex, int number)
{
    if (game.open[0][number] == "   " || game.open[targetIndex-1][number] == "@@@")
        return true;

    if (card1 != "   " && card2 != "   " && card2 != "@@@" && card1 != "@@@" &&card1 != "___" && card2 != "___") {
        int cardNumber1 = stoi(card1.substr(1, 2));
        int cardNumber2 = stoi(card2.substr(1, 2));

        if (cardNumber2 - cardNumber1 == 1)
        {
            if(card1[0] == 'H' || card1[0] == 'D')
                if(card2[0] == 'S' || card2[0] == 'C')
                    return true;

            if(card1[0] == 'S' || card1[0] == 'C')
                if(card2[0] == 'H' || card2[0] == 'D')
                    return true;
        }
        else
        {
            return false;
        }
        return false;
    }
}

void printUpperPartBefore(GameFunctions &game)
{
    if (game.tailCounter - game.headCounter == 1)
    {
//        cout << "___ ";
        outputFile << "___ ";
    }
    else
    {
//        cout << "@@@ ";
        outputFile << "@@@ ";
    }


    for(int i=0; i<3; i++)
    {
//        cout << game.tempStock[i] << " ";
        outputFile << game.tempStock[i] << " ";
    }
//    cout << "        ";
    outputFile << "        ";
    for(int i=0; i<4; i++)
    {
//        cout << game.foundationArea[i] << " ";
        outputFile << game.foundationArea[i] << " ";
    }
//    cout << endl << endl;
    outputFile << "\n\n";
}

void moveWaste(GameFunctions &game, int number)
{
    int insertIndex = findInsertLocation(game, number);

    int counter = -1;
    for (int i = 0; i < 3; ++i) {
        if(game.stock2[game.headCounter][i] != "___")
            counter++;
    }

    if(insertIndex == -1)
    {
        string cardCheck = game.stock2[game.headCounter][counter];
        int cardNumberCheck = stoi(cardCheck.substr(1, 2));
        if (game.open[0][number] == "   " && cardNumberCheck != 13)
        {
//            cout<< "Invalid Move!" << endl;
            outputFile << "Invalid Move!\n";
            return;
        }

        game.open[insertIndex+1][number] = game.stock2[game.headCounter][counter];
        game.stock2[game.headCounter][counter] = "___";

        int stockCounter = -1;

        for (int i = 0; i < 3; i++) {
            if (game.stock2[game.headCounter-1][i] != "___")
            {
                stockCounter++;
            }
        }

        if (counter == 0)
        {
            if(game.headCounter == 1)
            {
                game.tempStock[0] = "___";
            }
            else
            {
                game.tempStock[0] = game.stock2[game.headCounter-1][stockCounter];
            }
            game.tempStock[1] = "___";
            game.tempStock[2] = "___";
            game.check = true;
        }
        return;
    }


    if (counter == -1)
    {
//        cout<< "Invalid Move!" << endl;
        outputFile << "Invalid Move!\n";
        return;
    }

    string card1 = game.stock2[game.headCounter][counter];
    string card2 = game.open[insertIndex][number];


    bool check = suitabilityCheckTwo(game, card1, card2, insertIndex + 1, number);
    if (check)
    {
        if (counter == 0)
        {
            game.open[insertIndex+1][number] = game.stock2[game.headCounter][counter];
            game.stock2[game.headCounter][counter] = "___";
            if(game.headCounter != 0)
            {
                int fakeCounter = -1;

                for (int i = 0; i < 3; i++) {
                    if (game.stock2[game.headCounter-1][i] != "___")
                    {
                        fakeCounter++;
                    }
                }

                if(game.headCounter == 1)
                {
                    game.tempStock[0] = "___";
                }
                else
                {
                    game.tempStock[0] = game.stock2[game.headCounter-1][fakeCounter];
                }
                game.tempStock[1] = "___";
                game.tempStock[2] = "___";
                game.check = true;
            }
        }
        else
        {
            game.open[insertIndex+1][number] = game.stock2[game.headCounter][counter];
            game.stock2[game.headCounter][counter] = "___";
        }
    }
    else
    {
//        cout<< "Invalid Move!" << endl;
        outputFile << "Invalid Move!\n";
    }
}

void sortStockElements(GameFunctions &game)
{
    string tempArray[23];

    int counter = 0;
    int tailCounter = game.tailCounter-1;
    for (int i = 1; i <= tailCounter; i++) {
        for (int j = 0; j<3; j++) {
            if (game.stock2[i][j] == "___")
            {
                continue;
            }
            else
            {
                tempArray[counter] = game.stock2[i][j];
                counter++;
            }
        }
    }

    int counter2 = 0;
    int deleteCounter = 0;

    for (int i = 1; i < game.tailCounter; i++) {
        for (int j = 0; j < 3; j++) {
            if (counter2 >= counter)
            {
                game.stock2[i][j] = "___";
                deleteCounter++;
            }
            else
            {
                game.stock2[i][j] = tempArray[counter2];
                counter2++;
            }
        }
    }

    int divide = deleteCounter / 3;
    game.tailCounter = game.tailCounter - divide;
}

void openFromStock(GameFunctions &game)
{
    game.check = false;
    game.headCounter++;

    if (game.headCounter == game.tailCounter)
    {
        sortStockElements(game);
        game.headCounter = 0;
    }
}

void openCard(int openIndex, GameFunctions &game)
{
    int counterOpen = 0;
    int insert = findInsertLocation(game, openIndex);
    if (game.open[insert][openIndex] != "@@@" && game.open[insert-1][openIndex] != "   ")
    {
//        cout << "Invalid Move!" << endl;
        outputFile << "Invalid Move!\n";
        return;
    }

    for (int tableuIndex = 0; tableuIndex < 12; tableuIndex++) {
        if(game.open[tableuIndex][openIndex] != "   ")
        {
            if(game.open[tableuIndex][openIndex] == "@@@")
                counterOpen++;
            else
                break;
        }
    }
    game.open[counterOpen-1][openIndex] = game.tableMatrix[counterOpen - 1][openIndex];
}

void fillOpenDeck(GameFunctions &game, string *deck)
{
    int counter = 0;

    for (int i = 51; i >= 0; i--)
    {
        if(i == 51 || i == 44 || i == 38 || i == 33 || i == 29 || i == 26 || i == 24 )
        {
            game.open[counter][counter] = deck[i];
            counter++;
        }
    }
}

void copyStockToGameObject(GameFunctions &game, string *deck)
{
    int counter = 0;
    for(int i=8; i>=1; i--)
        for (int j = 2; j >= 0; j--) {
            game.stock2[i][j] = deck[counter++];
        }
    game.stock2[0][0] = "___";
    game.stock2[0][1] = "___";
    game.stock2[0][2] = "___";
}


void printUpperPartCurrent(GameFunctions &game)
{
    if (game.tailCounter-game.headCounter != 1)
    {
//        cout << "@@@ ";
        outputFile << "@@@ ";
    }
    else
    {
//        cout << "___ ";
        outputFile << "___ ";
    }

    for(int i=0; i<3; i++)
    {
//        cout << game.stock2[game.headCounter][i] << " ";
        outputFile << game.stock2[game.headCounter][i] << " ";
    }
//    cout << "        ";
    outputFile << "        ";
    for(int i=0; i<4; i++)
    {
//        cout << game.foundationArea[i] << " ";
        outputFile << game.foundationArea[i] << " ";
    }
//    cout << endl << endl;
    outputFile << "\n\n";
}

bool winCheck(GameFunctions &game)
{
    if (game.foundationArea[0] == "H13")
        if (game.foundationArea[1] == "D13")
            if (game.foundationArea[2] == "S13")
                if (game.foundationArea[3] == "C13")
                    return true;
    return false;
}