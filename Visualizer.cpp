#include<iostream>
#include<vector>
#include<string>
#include<fcntl.h>
#include<io.h>
#include<stdio.h>
#include<map>

#include "Visualizer.h"

using namespace std;

enum Pieces {wp,wn,wb,wr,wq,wk,bp,bn,bb,br,bq,bk,EMPTY};
map<string,wchar_t*> PiecemapB = {
    {"wp",L"\x2659"},
    {"wn",L"\x2658"},
    {"wb",L"\x2657"},
    {"wr",L"\x2656"},
    {"wq",L"\x2655"},
    {"wk",L"\x2654"},
    {"bp",L"\x265F"},
    {"bn",L"\x265E"},
    {"bb",L"\x265D"},
    {"br",L"\x265C"},
    {"bq",L"\x265B"},
    {"bk",L"\x265A"},
    {".",L"\xFFFC"}
};

wchar_t* getIconForPiece(Pieces);
vector<vector<string>> makeBoard();
void printBoardTop(vector<string>& row);
void printBoardPieceRow(vector<string>& row);
void printBoardSeparatingRow(vector<string>& row);
void printBoardBottom(vector<string>& row);
Pieces parseStringtoPiece(string input);

void presentBoard(){
    _setmode(_fileno(stdout), _O_U16TEXT);

    vector<vector<string>> board = makeBoard();

    printBoardTop(board[0]);
    //wprintf(L"\x2523\x2501\x2501\x2501\x254B");
    for (int i=0;i<board.size();i++)
    {
        printBoardPieceRow(board[i]);
        if (i != board.size()-1)
            printBoardSeparatingRow(board[i]);
    }
    printBoardBottom(board[0]);
    //print bottom line
}

vector<vector<string>> makeBoard(){
    return {
        {"br","bn","bb","bk","bq","bb","bn","br"},
        {"bp","bp","bp","bp","bp","bp","bp","bp"},
        {".",".",".",".",".",".",".","."},
        {".",".",".",".",".",".",".","."},
        {".",".",".",".",".",".",".","."},
        {".",".",".",".",".",".",".","."},
        {"wp","wp","wp","wp","wp","wp","wp","wp"},
        {"wr","wn","wb","wq","wk","wb","wn","wr"}
    };
}

wchar_t* getIconForPiece(Pieces input){
    wchar_t* foo = new wchar_t[2];
    switch(input)
    {
        case wp:
            foo=L"\x263a";
            break;
        default:
            foo=L"\x263a";
    }
    return foo;
}

void printBoardTop(vector<string>& row)
{
    wprintf(L"\x250F");//Top left corner
    for (int i=0; i<row.size()-1; i++)
    {
        wprintf(L"\x2501\x2501\x2501\x2533");
    }
    wprintf(L"\x2501\x2501\x2501\x2513\n");
}

void printBoardPieceRow(vector<string>& row)
{
    wprintf(L"\x2503");//Left side
    for (int i=0; i<row.size(); i++)
    {
        wprintf(L"\xFFFC");
        wprintf(PiecemapB[row[i]]);
        wprintf(L"\xFFFC\x2503");
    }
    wprintf(L"\n");

}

void printBoardSeparatingRow(vector<string>& row)
{
    wprintf(L"\x2523");
    for (int i=0; i<row.size()-1; i++)
    {
        wprintf(L"\x2501\x2501\x2501");
        wprintf(L"\x254B");
    }
    wprintf(L"\x2501\x2501\x2501");
    wprintf(L"\x252B\n");
}

void printBoardBottom(vector<string>& row)
{
    wprintf(L"\x2517");
    for (int i = 0; i < row.size()-1; i++)
    {
        wprintf(L"\x2501\x2501\x2501");
        wprintf(L"\x253B");
    }
    wprintf(L"\x2501\x2501\x2501");
    wprintf(L"\x251B\n");
}