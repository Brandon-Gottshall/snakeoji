#ifndef SNAKE_H
#define SNAKE_H

#define MAX_SNAKE_LENGTH 100  // Explanation: Maximum length of the snake.

void initialize_snake();       // Explanation: Initialize the snake's position.
void update_snake(int dx, int dy);  // Explanation: Update the snake's position.

extern int snake_x[MAX_SNAKE_LENGTH];  // Explanation: Snake x-coordinates.
extern int snake_y[MAX_SNAKE_LENGTH];  // Explanation: Snake y-coordinates.
extern int snake_length;               // Explanation: Current length of the snake.

#endif

// Explanation: The snake module defines functions and variables related to the snake's behavior. The MAX_SNAKE_LENGTH constant specifies the maximum length of the snake. The initialize_snake function initializes the snake's position, and the update_snake function updates the snake's position based on movement offsets. The snake_x and snake_y arrays store the x and y coordinates of each snake segment, while the snake_length variable tracks the current length of the snake. By encapsulating the snake logic in a separate module, the codebase becomes more modular, maintainable, and extensible. The snake module provides an interface for interacting with the snake's position and behavior, enabling the main game loop to control the snake's movement and update its position accordingly.