# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = build/snakoji
SRC = src/main.c src/board/board.c src/snake/snake.c src/utils/utils.c
OBJ = $(SRC:%.c=build/%.o)

# Default Target
all: $(TARGET)

# Link Object Files to Create Executable
$(TARGET): $(OBJ)
	@mkdir -p build
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile Each Source File to Object File
build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the Program
run: $(TARGET)
	./$(TARGET)

# Clean Up Compiled Files
clean:
	rm -f $(TARGET) $(OBJ)
