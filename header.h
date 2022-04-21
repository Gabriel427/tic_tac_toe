#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void startgame(char choise);
vector<char> initializeTable(vector<char> table);
void showtable(vector<char> table );
vector<char> makeplay(vector<char> table, char choise,int option);
vector<char> playerTurn(vector<char> table, char choise);
vector<char> cpuTurn(vector<char> table, char choise);