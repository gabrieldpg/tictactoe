#include <iostream>
#include <string>

class TicTacToe {
private:
        const char players[2] = {'X', 'O'};  // 2 players, X and O
        char board[3][3];                    // 3x3 board

public:
	// Initialise board with:
        //                 ...
        //                 ...
        //                 ...
        void initBoard();

        // Show board
        void showBoard();

        // Check if game is finished
        // Returns: 0 if game is not finished
        //          1 if Player 1 has won
        //	    2 if Player 2 has won
        //	    -1 if game is finished and no one has won
        int isGameFinished();

        // Returns true if player won the game, false otherwise
        bool playerWon(char player);

        // Returns player at position i, 0 is X and 1 is O
        char getPlayer(int i);

        // Returns char in board at x,y, returns ., X or O
        char boardAt(int x, int y);

        // Adds Player char (X or O) to board at position x,y
        void newMove(int i, int x, int y);

};