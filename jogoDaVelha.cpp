#include "header.h"
// interface com o usuário
int main()
{
    char option, choise;
    do
    {
        cout << "Do you wish to play tick-tac-toe?\ny=yes    n=no\n";
        cin >> option;
    } while (option != 'y' && option != 'Y' && option != 'n' && option != 'N');
    if (option == 'y' || option == 'Y')
    {
        do
        {
            cout << "Do you wanna play with X ou O ?";
            cin >> choise;
        } while (choise != 'x' && choise != 'X' && choise != 'o' && choise != 'O');
        startgame(choise);
    }
    else
        cout << ("Thanks for playing\n");
    return 0;
}

void startgame(char choise)
{
    vector<char> table(9);
    table = initializeTable(table);
    bool turn = true;
    int win = -1;
    do
    {
        win = verifyWin();
        if (turn)
        {
            showtable(table);
            table = playerTurn(table, choise);
        }
        else
        {
            table = cpuTurn(table, choise);
        }
        turn = !turn;
    } while (win == -1);

    cout << "Fim do jogo";
}

vector<char> initializeTable(vector<char> table)
{
    char charValue;
    for (int i = 0; i < 10; i++)
    {
        char charValue = i + '0';
        table[i] = charValue;
    }
    return table;
}

void showtable(vector<char> table)
{
    for (int i = 0; i < 3; i++)
    {
        cout << " | " << table[i] << " | ";
    }
    cout << "\n--------------------\n";
    for (int i = 3; i < 6; i++)
    {
        cout << " | " << table[i] << " | ";
    }
    cout << "\n--------------------\n";
    for (int i = 6; i < 9; i++)
    {
        cout << " | " << table[i] << " | ";
    }
    cout << "\n--------------------\n";
}

vector<char> playerTurn(vector<char> table, char choise)
{
    int option = -1;
    do
    {
        cout << "Where do you wanna put a marcation ?";
        cin >> option;
    } while (option < 0 || option > 9);
    table = makeplay(table, choise, option);
    return table;
}

vector<char> cpuTurn(vector<char> table, char choise)
{
    cout << "In progress\n";
    return table;
}

vector<char> makeplay(vector<char> table, char choise, int option)
{
    if (table[option] == 'x' || table[option] == 'X' || table[option] == 'o' || table[option] == 'O')
    {
        cout << "invalid option\n";
        showtable(table);
        option = -1;
        do
        {
            cout << "Where do you wanna put a marcation ?";
            cin >> option;
        } while (option < 0 || option > 9);
        table = makeplay(table, choise, option);
        return table;
    }
    else
    {
        if (choise == 'x' || choise == 'X')
        {
            table[option] = 'X';
        }
        else
        {
            table[option] = 'O';
        }
        return table;
    }
}

int verifyWin(vector<char> table)
{
    cout << "verify if someone win under construiction";
}