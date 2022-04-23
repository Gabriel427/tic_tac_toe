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
    } while (option != 'Y' && option != 'N');
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
    vector<char> board(9);
    board = initializeBoard(board);
    bool turn = true;
    int win = -1;
    do
    {
        if (turn)
        {
            showBoard(board);
            board = playerTurn(board, choise);
        }
        else
        {
            //cout << "Chegou aqui";
            //board = cpuTurn(board, choise);
            board = bestMove(board, choise);
        }
        win = verifyWin(board, choise);
        turn = !turn;
    } while (win == -1);

    if (win == -10)
    {
        printf("----------You Win !!----------\n");
        showBoard(board);
    }
    else if (win == 10)
    {
        printf("----------You Lose !!----------\n");
        showBoard(board);
    }
    else
    {
        printf("----------It's a Tie !!----------\n");
        showBoard(board);
    }
    cout << "End of the game\n";
}

bool equals(char p1, char p2, char p3)
{
    if (p1 == p2 && p2 == p3)
        return true;
    else
        return false;
}

int verifyWin(vector<char> board, char choise)
{
    // verifica se o jogo foi ganho
    if (equals(board[0], board[1], board[2]))
    {
        if (choise == board[0])
        {
            return -10;
        }
        else
        {
            return 10;
        }
    }
    else if (equals(board[0], board[3], board[6]))
    {
        if (choise == board[0])
        {
            return -10;
        }
        else
        {
            return 10;
        }
    }
    else if (equals(board[0], board[4], board[8]))
    {
        if (choise == board[0])
        {
            return -10;
        }
        else
        {
            return 10;
        }
    }
    else if (equals(board[1], board[4], board[7]))
    {
        if (choise == board[1])
        {
            return -10;
        }
        else
        {
            return 10;
        }
    }
    else if (equals(board[2], board[5], board[8]))
    {
        if (choise == board[2])
        {
            return -10;
        }
        else
        {
            return 10;
        }
    }
    else if (equals(board[2], board[4], board[6]))
    {
        if (choise == board[2])
        {
            return -10;
        }
        else
        {
            return 10;
        }
    }
    else if (equals(board[3], board[4], board[5]))
    {
        if (choise == board[3])
        {
            return -10;
        }
        else
        {
            return 10;
        }
    }
    else if (equals(board[6], board[7], board[8]))
    {
        if (choise == board[6])
        {
            return -10;
        }
        else
        {
            return 10;
        }
    }
    else if (isTie(board))
        return 0;
    return -1;
}

bool isTie(vector<char> board)
{
    int count = 0;
    for (int i = 0; i <= board.size()-1; i++)
    {
        if (board[i] == 'X' || board[i] == 'O')
            count++;
    }
    if (count == 9)
        return true;
    else
        return false;
}

vector<char> initializeBoard(vector<char> board)
{
    char charValue;
    for (int i = 0; i <= board.size()-1; i++)
    {
        char charValue = i + '0';
        board[i] = charValue;
    }
    return board;
}

void showBoard(vector<char> board)
{
    for (int i = 0; i < 3; i++)
    {
        cout << " | " << board[i] << " | ";
    }
    cout << "\n--------------------\n";
    for (int i = 3; i < 6; i++)
    {
        cout << " | " << board[i] << " | ";
    }
    cout << "\n--------------------\n";
    for (int i = 6; i < 9; i++)
    {
        cout << " | " << board[i] << " | ";
    }
    cout << "\n--------------------\n";
}

vector<char> playerTurn(vector<char> board, char choise)
{
    int option = -1;
    do
    {
        cout << "Where do you wanna put a marcation ?";
        cin >> option;
    } while (option < 0 || option > board.size()-1);
    board = makeplay(board, choise, option);
    return board;
}

vector<char> cpuTurn(vector<char> board, char choise)
{
    char cpuChoise;
    if (choise == 'X')
        cpuChoise = 'O';
    else
        cpuChoise = 'X';
    for (int i = 0; i <= board.size()-1; i++)
    {
        if (board[i] != 'X' && board[i] != 'O')
        {
            board = makeplay(board, cpuChoise, i);
            return board;
        }
    }

    return board;
}

vector<char> makeplay(vector<char> board, char choise, int option)
{
    if (board[option] == 'X' || board[option] == 'O')
    {
        cout << "invalid option\n";
        showBoard(board);
        option = -1;
        do
        {
            cout << "Where do you wanna put a marcation ?";
            cin >> option;
        } while (option < 0 || option > 9);
        board = makeplay(board, choise, option);
        return board;
    }
    else
    {
        if (choise == 'X')
        {
            board[option] = 'X';
        }
        else
        {
            board[option] = 'O';
        }
        return board;
    }
}

vector<char> bestMove( vector<char> board, char choise)
{
    // AI to make its turn
    int bestScore = INT_MIN;
    int move = 0;
    char cpuChoise;
    if (choise == 'X')
        cpuChoise = 'O';
    else
        cpuChoise = 'X';
    for (int i = 0; i <= board.size()-1; i++)
    {
        if (board[i] != 'X' && board[i] != 'O')
        {
            board[i] = cpuChoise;
            int score = minimax(board, 0, false, choise);
            board[i] = i + '0';
            if (score > bestScore)
            {
                bestScore = score;
                move = i;
            }
        }
    }
    board = makeplay(board, cpuChoise, move);
    return board;
}

int minimax(vector<char> board, int depth, bool isMaximizing, char choise)
{
    char cpuChoise;
    if (choise == 'X')
        cpuChoise = 'O';
    else
        cpuChoise = 'X';

    int result = verifyWin(board, choise);
    if (result != -1)
    {
        return verifyWin(board, choise);
    }
    if (isMaximizing)
    {
        int bestScore = INT_MIN;
        for (int i = 0; i <= board.size()-1; i++)
        {
            if (board[i] != 'X' && board[i] != 'O')
            {
                board[i] = cpuChoise;
                int score = minimax(board, depth + 1, false, choise);
                board[i] = i + '0';
                bestScore = max(score, bestScore);
            }
        }
        return bestScore;
    }
    else
    {
        int bestScore = INT_MAX;
        for (int i = 0; i <= board.size()-1; i++)
        {
            if (board[i] != 'X' && board[i] != 'O')
            {
                board[i] = choise;
                int score = minimax(board, depth + 1, true, choise);
                board[i] = i + '0';
                bestScore = min(score, bestScore);
            }
        }
        return bestScore;
    }
}