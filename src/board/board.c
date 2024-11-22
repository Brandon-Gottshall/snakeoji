#include <stdio.h> // Explanation: For standard I/O functions like printf
#include "board.h" // Explanation: Include the board header file to access the board functions
#include "../snake/snake.h" // Explanation: Include the snake header file to access the snake's position

// Explanation: 2D array representing the game board.
char board[HEIGHT][WIDTH];

// Explanation: Initialize the game board with borders and place the snake.
void initialize_board() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Explanation: Set up the top and bottom borders.
            if (i == 0 || i == HEIGHT - 1) {
                board[i][j] = (j == 0 || j == WIDTH - 1) ? '+' : '-';
            } 
            // Explanation: Set up the left and right borders.
            else {
                board[i][j] = (j == 0 || j == WIDTH - 1) ? '|' : ' ';
            }
        }
    }

    // Explanation: Place the snake on the board, starting with the head.
    for (int i = 0; i < snake_length; i++) {
        board[snake_y[i]][snake_x[i]] = (i == 0) ? 'O' : 'o';
    }
}

// Explanation: Print the game board to the terminal.
void print_board() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);  // Explanation: Print each cell of the board.
        }
        printf("\n");  // Explanation: Newline after each row.
    }
}
// Explanation: The board module provides functions to initialize and print the game board. The board is represented as a 2D array of characters, with borders and the snake's position updated accordingly. The initialize_board function sets up the borders and places the snake on the board, while the print_board function displays the board in the terminal. These functions are used in the main game loop to update and visualize the game state. The board module encapsulates the logic related to the game board, promoting modularity and separation of concerns in the codebase.