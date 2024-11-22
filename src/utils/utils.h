#ifndef UTILS_H
#define UTILS_H

void clear_screen();            // Explanation: Clear the terminal screen.
void sleep_ms(int milliseconds);  // Explanation: Sleep for a specified duration.
void enable_noncanonical_mode(); // Explanation: Enable non-canonical input mode.
void reset_terminal_mode();      // Explanation: Reset terminal to canonical mode.

#endif

// Explanation: The utils module provides utility functions for managing terminal input and output, including clearing the screen, sleeping for a specified duration, enabling non-canonical input mode, and resetting the terminal mode. These functions are used to control the game's behavior, manage user input, and provide a better user experience. By encapsulating these utility functions in a separate module, the codebase becomes more modular, maintainable, and portable. The utils module abstracts platform-specific functionality and terminal input management, allowing the main game logic to focus on game-specific behavior and interactions. The separation of concerns between game logic and utility functions improves code organization and readability, making it easier to maintain and extend the game.