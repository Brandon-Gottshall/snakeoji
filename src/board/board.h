#ifndef BOARD_H
#define BOARD_H

#define HEIGHT 15  // Explanation: Game board height.
#define WIDTH 50   // Explanation: Game board width.

void initialize_board();  // Explanation: Initialize the board.
void print_board();       // Explanation: Print the board.

extern char board[HEIGHT][WIDTH];  // Explanation: 2D array for the game board.

#endif

// Explanation: The board module defines functions and constants related to the game board. The HEIGHT and WIDTH constants specify the dimensions of the game board. The initialize_board function initializes the game board, and the print_board function displays the current state of the board. The board module encapsulates the game board logic, providing an interface for interacting with the game board. This separation of concerns improves code organization and readability, making it easier to manage the game board functionality.
