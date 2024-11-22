#include "snake.h" // Explanation: Include the snake header file to access the snake functions

// Explanation: Snake length (initially 3 segments).
int snake_length = 3;

// Explanation: Arrays to store the x and y coordinates of each snake segment.
int snake_x[MAX_SNAKE_LENGTH];
int snake_y[MAX_SNAKE_LENGTH];

// Explanation: Initialize the snake's starting position.
void initialize_snake() {
    snake_x[0] = 10; snake_y[0] = 10;  // Explanation: Head
    snake_x[1] = 9;  snake_y[1] = 10;  // Explanation: Body
    snake_x[2] = 8;  snake_y[2] = 10;  // Explanation: Tail
}

// Explanation: Update the snake's position based on movement offsets.
void update_snake(int dx, int dy) {
    // Explanation: Move each segment to follow the segment ahead of it.
    for (int i = snake_length - 1; i > 0; i--) {
        snake_x[i] = snake_x[i - 1];
        snake_y[i] = snake_y[i - 1];
    }

    // Explanation: Move the head based on the user's input.
    snake_x[0] += dx;
    snake_y[0] += dy;
}

// Explanation: The snake module defines functions to initialize and update the snake's position. The snake's position is represented by arrays storing the x and y coordinates of each segment. The initialize_snake function sets the initial position of the snake, while the update_snake function moves the snake based on user input. These functions are used in the main game loop to control the snake's movement. The snake module encapsulates the logic related to the snake's behavior, promoting code organization and maintainability.