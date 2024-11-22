#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include "utils.h"

// Explanation: Clear the terminal screen (platform-dependent).
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[H\033[J");  // Explanation: ANSI escape codes for Unix-based systems.
#endif
}

// Explanation: Sleep for a specified number of milliseconds.
void sleep_ms(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);  // Explanation: Windows-specific sleep function.
#else
    usleep(milliseconds * 1000);  // Explanation: POSIX-compliant sleep function.
#endif
}

// Explanation: Enable non-canonical terminal mode for real-time input.
void enable_noncanonical_mode() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);       // Explanation: Get current terminal attributes.
    t.c_lflag &= ~(ICANON | ECHO);    // Explanation: Disable canonical mode and echo.
    tcsetattr(STDIN_FILENO, TCSANOW, &t);  // Explanation: Apply changes immediately.
}

// Explanation: Reset the terminal to its original mode.
void reset_terminal_mode() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);      // Explanation: Get current terminal attributes.
    t.c_lflag |= (ICANON | ECHO);     // Explanation: Enable canonical mode and echo.
    tcsetattr(STDIN_FILENO, TCSANOW, &t);  // Explanation: Apply changes immediately.
}

// Explanation: The utils module provides utility functions for clearing the screen, sleeping for a specified duration, and managing terminal input modes. The clear_screen function clears the terminal screen using platform-specific commands. The sleep_ms function pauses the program execution for a specified number of milliseconds. The enable_noncanonical_mode and reset_terminal_mode functions modify the terminal input mode to enable real-time input without requiring the user to press Enter. These utility functions are used in the main game loop to control the game's behavior and user interaction. The utils module encapsulates platform-specific functionality and terminal input management, promoting code reusability and portability.