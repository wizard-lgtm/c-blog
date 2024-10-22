# Compiler
CC = gcc

# Compiler flags

CFLAGS = -Wall -Wextra -I./include -I/usr/local/include

# Linker flags
LDFLAGS = -lcmark

# Source file
SRC = $(wildcard *.c)

# Output executable
TARGET = c-blog 

# Build the executable
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Clean up
clean:
	rm -f $(TARGET)

run:
	./c-blog

