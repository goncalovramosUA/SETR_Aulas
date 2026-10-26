# Compiler & Flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

# PATHS
SRC_FOLDER = src
BUILD_FOLDER = build

MODULE = ex3
TARGET = $(BUILD_FOLDER)/$(MODULE)

.PHONY: all default clear ex3_1 ex3_2 

all: default

default: ex3_1

$(BUILD_FOLDER):
	mkdir -p $(BUILD_FOLDER)

$(TARGET)_1: $(SRC_FOLDER)/$(MODULE)_1.c | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $(SRC_FOLDER)/$(MODULE)_1.c -o $(TARGET)_1 $(LDFLAGS)

$(TARGET)_2: $(SRC_FOLDER)/$(MODULE)_2.c | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $(SRC_FOLDER)/$(MODULE)_2.c -o $(TARGET)_2 $(LDFLAGS)

ex3_1: $(TARGET)_1
	./$(TARGET)_1

ex3_2: $(TARGET)_2
	./$(TARGET)_2

clean:
	rm -rf &(BUILD_FOLDER)