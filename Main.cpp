// TicTacToe by Gabriel

#include <iostream>
#include <string>
#include "TicTacToe.h"

using namespace std;

int main() { 

        TicTacToe game;
        int i = 0;  // Keeps track of which player's turn it is
        int winner;
        string move;
        int x,y;
        char newGame; // y if playing new game, n if not
        bool played = true; // Keeps track of wether player i has played yet

        game.initBoard();
        cout << "Welcome to Tic Tac Toe!" << endl << endl;

        while (true) {

                // If prev player has played, display updated board
                if (played) {
                        game.showBoard();
                }

                winner = game.isGameFinished(); // returns 0 if not finished, 1 if player 1 wins, 2 if player 2 wins and -1 if no one wins

                if (winner == 0) { // Game not over

                        cout << "Player " << i+1 << " enter coordinates x,y to place your '" << game.getPlayer(i) << "' or enter 'q' to give up: ";
                        cin >> move;
                        //cout << endl;

                        if (move.length() == 1 && move.compare("q") == 0) { // Player gave up

                                cout << "Game Over!" << endl << endl;
                                cout << "Would you like to play again? (y/n): ";
                                cin >> newGame;
                                cout << endl;

                                if (newGame == 'y') { // If playing new game
                                        // Reset board, start with player 0, set played to true
                                        game.initBoard();
                                        i = 0;
                                        played = true;
                                } else {
                                        exit(1);
                                }

                        } else if (move.length() == 3 && move[1] == ',' &&
                                move[0] >= '1' && move[2] >= '1' &&
                                move[0] <= '3' && move[2] <= '3') { // Valid input

                                x = move[0]-'0'; // Converting char to int
                                y = move[2]-'0'; // Converting char to int

                                if (game.boardAt(x,y) == '.') { // Coordinate not yet taken

                                        cout << "Move accepted!" << endl;

                                        // Add X or O to board
                                        game.newMove(i,x,y);

                                        // Change players
                                        if (i == 0) {
                                                i = 1;
                                        } else {
                                                i = 0;
                                        }

                                        played = true;

                                } else {
                                        cout << "Move already taken! Please try again..." << endl << endl;
                                        played = false;
                                }

                        } else { // Invalid input
                                cout << "Invalid input! Please enter within range 1,1 to 3,3. Try again..." << endl << endl;
                                played = false;
                        }

                } else { // Game is over

                        if (winner == -1) {
                                cout << "It's a DRAW! No one wins..." << endl;
                                cout << "Would you like to play again? (y/n): ";
                                cin >> newGame;
                        } else if (winner > 0) {
                                cout << "Player " << winner << " wins!" << endl;
                                cout << "Would you like to play again? (y/n): ";
                                cin >> newGame;
                        }

                        cout << endl;

                        if (newGame == 'y') { // If playing new game
                                // Reset board, start with player 0, set played to true
                                game.initBoard();
                                i = 0;
                                played = true;
                        } else {
                                exit(1);
                        }
                }
        }
} 