#include<iostream>
#include<regex>

#include "Visualizer.h"

using namespace std;

void mainMenu();
string userInput();
void awaitMove();

int main()
{
    mainMenu();
    system("CLS");
    presentBoard();
    
}

void mainMenu()
{
    cout << "Welcome to Chess!\n";
    cout << "Press any button to continue\n";
    userInput();
}

string userInput()
{
    string input;
    cin >> input;
    return input;
}

void awaitMove()
{
    string input;
    cout << "Enter your move:";
    cin >> input;

}

string validateMove()
{
    //K = king
    //Q = queen
    //R = rook
    //B = bishop
    //N = knight
    //no notation = pawn
    //a-h, 1-8
    //to prevent ambiguity, you can add either the rank or the file after the letter. 
    //castle is O-O or O-O-O, not necessary
    //a + is added to the from when putting into check, not necessary
    //an x is added between pieces when capturing
    // 
}