SRC_DIR = src
OBJ_DIR = bin

TARGET = civsim # executable name
CC = g++ # name of compiler
CFLAGS = -Wall -Wextra -Iinclude # compilation flags

SRC = $(wildcard $(SRC_DIR)/*.cpp) # compile all `.cpp` files in SRC_DIR
OUT = $(OBJ_DIR)/$(TARGET)

all:
	@echo "Building Civ Sim..."
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	@echo "Civ Sim successfully built at $(OBJ_DIR)/$(TARGET)!"

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
