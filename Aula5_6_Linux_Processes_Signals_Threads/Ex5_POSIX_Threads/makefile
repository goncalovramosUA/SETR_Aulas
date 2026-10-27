# Compiler & Flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm -pthread

# PATHS
SRC_FOLDER = src
BUILD_FOLDER = build

# MODULE
MODULE = ex5
TARGET = $(BUILD_FOLDER)/$(MODULE)


.PHONY: all default clean ex5_1 ex5_2 ex5_3

all: default

default: ex5_1

$(BUILD_FOLDER):
	mkdir -p $(BUILD_FOLDER)

$(TARGET)_1: $(SRC_FOLDER)/$(MODULE)_1.c | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $(SRC_FOLDER)/$(MODULE)_1.c -o $(TARGET)_1 $(LDFLAGS)

$(TARGET)_2: $(SRC_FOLDER)/$(MODULE)_2.c | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $(SRC_FOLDER)/$(MODULE)_2.c -o $(TARGET)_2 $(LDFLAGS)

$(TARGET)_3: $(SRC_FOLDER)/$(MODULE)_3.c | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $(SRC_FOLDER)/$(MODULE)_3.c -o $(TARGET)_3 $(LDFLAGS)

ex5_1: $(TARGET)_1
	./$(TARGET)_1

ex5_2: $(TARGET)_2
	./$(TARGET)_2

ex5_3: $(TARGET)_3
	./$(TARGET)_3

clean:
	rm -rf $(BUILD_FOLDER)