# Compiler and flags
CC = g++
CFLAGS = -Wall -std=c++17
LIBS = -levdev  # evdev library for global key detection

# Targets (program names)
TARGET1 = klakkify    # Terminal version
TARGET2 = globalklakkify         # Global version

# Object files
OBJ1 = main.o sound.o
OBJ2 = globalkeys.o sound.o

# ===========================
# Default Target (Compiles Both)
# ===========================
all: $(TARGET1) $(TARGET2)

# ===========================
# Terminal-only Version
# ===========================
$(TARGET1): $(OBJ1)
	$(CC) $(CFLAGS) -o $(TARGET1) $(OBJ1)

main.o: src/main.cpp src/sound.h
	$(CC) $(CFLAGS) -c src/main.cpp

# ===========================
# Global Key Listener Version
# ===========================
$(TARGET2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(TARGET2) $(OBJ2) $(LIBS)

globalkeys.o: src/globalkeys.cpp src/sound.h
	$(CC) $(CFLAGS) -c src/globalkeys.cpp $(LIBS)

# ===========================
# Common Sound Object
# ===========================
sound.o: src/sound.cpp src/sound.h
	$(CC) $(CFLAGS) -c src/sound.cpp

# ===========================
# Clean Target
# ===========================
clean:
	rm -f $(OBJ1) $(OBJ2) $(TARGET1) $(TARGET2)

