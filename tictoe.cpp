#include <iostream>
#include <vector>

using namespace std;


void displayBoard(const vector<vector<char> >& board) {
    cout << "\nCurrent Board:\n";
    cout << "-------------\n";
    for (size_t i = 0; i < board.size(); ++i) {
        cout << "| ";
        for (size_t j = 0; j < board[i].size(); ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}


bool checkWin(const vector<vector<char> >& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}


bool checkDraw(const vector<vector<char> >& board) {
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}


void resetBoard(vector<vector<char> >& board) {
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j) {
            board[i][j] = ' ';
        }
    }
}

int main() {
    vector<vector<char> > board(3, vector<char>(3, ' '));  
    char currentPlayer = 'X';
    char playAgain;

    cout << "Welcome to Tic-Tac-Toe!\n";

    do {
        do {
            displayBoard(board);

            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                board[row][col] = currentPlayer;

                if (checkWin(board, currentPlayer)) {
                    displayBoard(board);
                    cout << "Player " << currentPlayer << " wins!\n";
                    break;
                }

                if (checkDraw(board)) {
                    displayBoard(board);
                    cout << "It's a draw!\n";
                    break;
                }

                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';  // Switch player
            } else {
                cout << "Invalid move. Try again.\n";
            }

        } while (true);

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        if (playAgain == 'Y' || playAgain == 'y') {
            resetBoard(board);
            currentPlayer = 'X';
        } else {
            cout << "Thanks for playing!\n";
            break;
        }

    } while (true);

    return 0;
}

