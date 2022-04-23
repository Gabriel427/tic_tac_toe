#include <stdio.h>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void startgame(char choise);
vector<char> initializeBoard(vector<char> board);
void showBoard(vector<char> board );
vector<char> makeplay(vector<char> board, char choise,int option);
vector<char> playerTurn(vector<char> board, char choise);
vector<char> cpuTurn(vector<char> board, char choise);
int verifyWin(vector<char> board, char choise);
bool equals(char p1, char p2, char p3);
vector<char> bestMove(vector<char>board,char choise);
int minimax(vector<char> board, int depth, bool isMaximizing,char choise);
bool isTie(vector<char>board);