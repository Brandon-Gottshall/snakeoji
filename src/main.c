#include <stdio.h>           // Explanation: For standard I/O functions like printf
#include <stdlib.h>          // Explanation:  For system commands and memory management
#include <unistd.h>          // Explanation:  For POSIX API (usleep, read)
#include "board/board.h"     // Game board logic
#include "snake/snake.h"     // Snake behavior
#include "utils/utils.h"     // Utility functions

int main() {
    // Explanation: Enable non-canonical mode for immediate key input without Enter.
    enable_noncanonical_mode();

    // Explanation: Register a cleanup function to restore terminal mode when the program exits.
    atexit(reset_terminal_mode);

    // Explanation: Initialize the snake's starting position.
    initialize_snake();

    // Explanation: Main game loop.
    while (1) {
        // Explanation: Clear the screen for each frame to simulate game animation.
        clear_screen();

        // Explanation: Reinitialize the board, placing the snake at its updated position.
        initialize_board();

        // Explanation: Print the game board to the terminal.
        print_board();

        // Explanation: Pause briefly to control game speed (200ms).
        sleep_ms(200);

        // Explanation: Capture non-blocking input from the user.
        char c;
        int dx = 0, dy = 0;  // Movement offsets (dx = horizontal, dy = vertical)
        if (read(STDIN_FILENO, &c, 1) > 0) {
            // Explanation: Handle input to move the snake or quit the game.
            if (c == 'q') break;        // Quit the game
            if (c == 'w') { dx = 0; dy = -1; }  // Move up
            if (c == 's') { dx = 0; dy = 1; }   // Move down
            if (c == 'a') { dx = -1; dy = 0; }  // Move left
            if (c == 'd') { dx = 1; dy = 0; }   // Move right
        }

        // Explanation: Update the snake's position based on user input.
        update_snake(dx, dy);
    }

    return 0;
}

// Explanation: The main function serves as the entry point for the game. It initializes the game components, enters the main game loop, and handles user input to control the snake's movement. The game loop consists of clearing the screen, updating the board, printing the board, pausing briefly, and processing user input to move the snake. The game loop continues until the user quits by pressing 'q'. The main function encapsulates the game logic and orchestrates the interactions between different modules, such as the board, snake, and utility functions. By structuring the code in this way, the game's functionality is modular, maintainable, and extensible.

// Explanation: of Header Files: // The header files (snake.h, utils.h, board.h) define the interfaces for the corresponding modules, specifying the functions, constants, and external variables used by each module. These header files are included in the main.c file to access the functionality provided by the modules. By separating the interface declarations from the implementation details, header files promote encapsulation and modularity, allowing different parts of the program to interact through well-defined interfaces. This separation of concerns improves code organization, readability, and maintainability, enabling developers to work on different parts of the program independently. The header files serve as documentation for the public API of each module, providing a clear overview of the available functions and constants. By following a modular design with header files, the codebase becomes more structured, reusable, and easier to manage.