#include "TicTacToe.h"

using namespace std;

// Initialise board with:
//                 ...
//                 ...
//                 ...
void TicTacToe::initBoard() {
        int i,j;
        for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                        board[i][j] = '.';
                }
        }
}

// Show board
void TicTacToe::showBoard() {
        int i,j;
        cout << "Here's the current board:" << endl << endl;
        for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                        cout << board[i][j];
                }
                cout << endl;
        }
        cout << endl;
}

// Check if game is finished
// Returns: 0 if game is not finished
//          1 if Player 1 has won
//          2 if Player 2 has won
//          -1 if game is finished and no one has won
int TicTacToe::isGameFinished() {
        int i,j; 
        if (playerWon(players[0])) {
                // Player 1 wins
                return 1;

        } else if (playerWon(players[1])) {
                // Player 2 wins
                return 2;
        }
        bool finished = true;
        // Check if any tiles still available
        for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                        if (board[i][j] == '.') {
                                finished = false;
                        }
                }
        }
        if (finished) {
                // No one wins, and game is finished
                return -1;
        }
        // No one won yet and game is not over
        return 0;

}

// Returns true if player won the game, false otherwise
bool TicTacToe::playerWon(char player) {

	if ((board[0][0] == player && board[0][1] == player && board[0][2] == player) ||     // horizontal win
                (board[1][0] == player && board[1][1] == player && board[1][2] == player) || // horizontal win
                (board[2][0] == player && board[2][1] == player && board[2][2] == player) || // horizontal win

                (board[0][0] == player && board[1][0] == player && board[2][0] == player) || // vertical win
                (board[0][1] == player && board[1][1] == player && board[2][1] == player) || // vertical win
                (board[0][2] == player && board[1][2] == player && board[2][2] == player) || // vertical win

                (board[0][0] == player && board[1][1] == player && board[2][2] == player) || // diagonal win
                (board[2][0] == player && board[1][1] == player && board[0][2] == player)) { // diagonal win
		return true;
	}
	return false;
}

// Returns player at position i, 0 is X and 1 is O
char TicTacToe::getPlayer(int i) {
        return players[i];
}

// Returns char in board at x,y, returns ., X or O
char TicTacToe::boardAt(int x, int y) {
        // Convert coordinate to index equivalent
        x--;
        y--;
        return board[x][y];
}

// Adds Player char (X or O) to board at position x,y
void TicTacToe::newMove(int i, int x, int y) {
        // Convert coordinate to index equivalent
        x--;
        y--;
        board[x][y] = players[i];
}