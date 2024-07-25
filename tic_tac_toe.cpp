#include <iostream>
using namespace std;

const int SIZE = 3;

char board[SIZE][SIZE];


void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}


void displayBoard() {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// checking if the board is full
bool checkBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}


char getWinner() {
    // Checking rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // Checking diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return '-';
}

int main() {
    int row, col;
    char currentPlayer = 'X';
    bool gameOver = false;

    initializeBoard();

    while (!gameOver) {
        displayBoard();

        //  input the players move
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (e.g., 0 1): ";
        cin >> row >> col;

        // Check if the entred position is valid
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != '-') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        
        board[row][col] = currentPlayer;

        // Checking the winner or for a draw
        char winner = getWinner();
        if (winner != '-') {
            displayBoard();
            cout << "Player " << winner << " wins!" << endl;
            gameOver = true;
        } else if (checkBoard()) {
            displayBoard();
            cout << "It's a draw!" << endl;
            gameOver = true;
        } else {
            // Switching player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}





