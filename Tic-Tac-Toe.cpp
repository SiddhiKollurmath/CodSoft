#include <iostream>
  using namespace std;

const int boardsize = 3;

void printBoard(char board[][boardsize]) 
{
    cout << "   0   1   2" << endl;
    cout << " ---------------" << endl;

    for (int i = 0; i < boardsize; ++i) 
    {
        cout << i << " | ";
        for (int j = 0; j < boardsize; ++j) 
        {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << " ---------------" << endl;
    }
}

bool checkWin(char board[][boardsize], char player) 
{
    
    for (int i = 0; i < boardsize; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) 
        {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) 
    {
        return true;
    }

    return false;
}

bool isBoardFull(char board[][boardsize]) 
{
    for (int i = 0; i < boardsize; ++i) 
    {
        for (int j = 0; j < boardsize; ++j) 
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() 
{
    char board[boardsize][boardsize] = { { ' ', ' ', ' ' },
                                         { ' ', ' ', ' ' },
                                         { ' ', ' ', ' ' } }; 

    char currentplayer = 'X';

    while (true) 
    {
        cout<<"HELLO!! \n WELCOME TO TIC TAC TOE!! \n THIS IS A 2 PLAYER GAME\n ";
        printBoard(board);

        int row, col;
        cout << "PLAYER " << currentplayer << ", ENTER YOUR MOVE : "<<endl;
        cout<<"ROW:";
        cin >> row ;
        cout<<"COLUMN:";
        cin >> col;

        if (row < 0 || row >= boardsize || col < 0 || col >= boardsize || board[row][col] != ' ') 
        {
            cout << "Invalid Move. Try Again." << endl;
            continue;
        }

        board[row][col] = currentplayer;

        if (checkWin(board, currentplayer)) 
        {
            printBoard(board);
            cout << "Player " << currentplayer << " WINS!" << endl;
            break;
        }

        if (isBoardFull(board)) 
        {
            printBoard(board);
            cout << "IT's A TIE!" << endl;
            break;
        }

        if (currentplayer == 'X') 
        {
          currentplayer = 'O';
        } 
        else 
        {
          currentplayer = 'X';
        }
    }

    return 0;
}