
# Compiler and flags
CC = g++
CFLAGS = -Wall -std=c++17

# Target executable
TARGET = Klakkify

# Source files
SRCDIR = src
SRC = $(SRCDIR)/main.cpp $(SRCDIR)/sound.cpp

# Object files
OBJ = main.o sound.o

# Default target
all: $(TARGET)

# Compile the executable from object files
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile main.cpp to object file
main.o: $(SRCDIR)/main.cpp $(SRCDIR)/sound.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/main.cpp

# Compile sound.cpp to object file
sound.o: $(SRCDIR)/sound.cpp $(SRCDIR)/sound.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/sound.cpp

# Clean target to remove compiled files
clean:
	rm -f $(OBJ) $(TARGET)



