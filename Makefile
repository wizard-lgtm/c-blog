# Compiler
CC = gcc

# Compiler flags

CFLAGS = -Wall -Wextra -I./include -I/usr/local/include -I/usr/include/libmongoc-1.0 -I/usr/include/libbson-1.0

# Linker flags
LDFLAGS = -lcmark -ldotenv -lmongoc-1.0 -lbson-1.0

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

