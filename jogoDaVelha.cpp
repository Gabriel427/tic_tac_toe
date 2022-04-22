#include "header.h"
// interface com o usuário
int main()
{
    char option, choise;
    do
    {
        cout << "Do you wish to play tick-tac-toe?\ny=yes    n=no\n";
        cin >> option;
        option = towupper(option);
    } while (option != 'Y'&& option != 'N');
    if (option == 'Y')
    {
        do
        {
            cout << "Do you wanna play with X ou O ?";
            cin >> choise;
            choise = toupper(choise);
        } while (choise != 'X' && choise != 'O');
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
        if (turn)
        {
            showtable(table);
            table = playerTurn(table, choise);
        }
        else
        {
            table = cpuTurn(table, choise);
        }
        win = verifyWin(table,choise);
        turn = !turn;
    } while (win == -1);

    cout << "End of the game\n";
}

int verifyWin(vector<char> table, char choise)
{
    // verifica se o jogo foi ganho
    if (table[0] == table[1] && table[1] == table[2]) 
    {
        if (choise == table[0])
        {
            printf("----------You win !!----------\n");
        }
        else
        {
            printf("----------You lose !!----------\n");
        }
        showtable(table);
        return 1;
    }
    else if (table[0] == table[3] && table[3] == table[6]) 
    {
        if (choise == table[0])
        {
            printf("----------You win !!----------\n");
        }
        else
        {
            printf("----------You lose !!----------\n");
        }
        showtable(table);
        return 1;
    }
    else if (table[0] == table[4] && table[4] == table[8]) 
    {
        if (choise == table[0])
        {
            printf("----------You win !!----------\n");
        }
        else
        {
            printf("----------You lose !!----------\n");
        }
        showtable(table);
        return 1;
    }
    else if (table[1] == table[4] && table[4] == table[7]) 
    {
        if (choise == table[1])
        {
            printf("----------You win !!----------\n");
        }
        else
        {
            printf("----------You lose !!----------\n");
        }
        showtable(table);
        return 1;
    }
    else if (table[2] == table[5] && table[5] == table[8]) 
    {
        if (choise == table[2])
        {
            printf("----------You win !!----------\n");
        }
        else
        {
            printf("----------You lose !!----------\n");
        }
        showtable(table);
        return 1;
    }
    else if (table[2] == table[4] && table[4] == table[6]) 
    {
        if (choise == table[2])
        {
            printf("----------You win !!----------\n");
        }
        else
        {
            printf("----------You lose !!----------\n");
        }
        showtable(table);
        return 1;
    }
    else if (table[3] == table[4] && table[4] == table[5]) 
    {
        if (choise == table[3])
        {
            printf("----------You win !!----------\n");
        }
        else
        {
            printf("----------You lose !!----------\n");
        }
        showtable(table);
        return 1;
    }
    else if (table[6] == table[7] && table[7] == table[8]) 
    {
        if (choise == table[6])
        {
            printf("----------You win !!----------\n");
        }
        else
        {
            printf("----------You lose !!----------\n");
        }
        showtable(table);
        return 1;
    }

    return -1;
}

vector<char> initializeTable(vector<char> table)
{
    char charValue;
    for (int i = 0; i <= table.size(); i++)
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
    char cpuChoise;
    if(choise == 'X')
        cpuChoise = 'O';
    else
        cpuChoise = 'X';
    for (int i = 0; i <= table.size(); i++)
    {
        if (table[i] != 'X'&& table[i] != 'O')
        {
            table = makeplay(table,cpuChoise, i);
            return table;
        }
    }
    
    return table;
}

vector<char> makeplay(vector<char> table, char choise, int option)
{
    if (table[option] == 'X'|| table[option] == 'O')
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
        if (choise == 'X')
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