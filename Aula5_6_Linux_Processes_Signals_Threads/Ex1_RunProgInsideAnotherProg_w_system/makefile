# Compiler & Flags
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra
LDFLAGS = -lm

# PATHS
SRC_FOLDER = src
BUILD_FOLDER = build


.PHONY: all default test clean ex1_1 ex1_2 ex1_3 ex1_4

all: default

default: ex1_1

$(BUILD_FOLDER):
	mkdir -p $(BUILD_FOLDER)

$(BUILD_FOLDER)/myPS: $(SRC_FOLDER)/myPS.c | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $(SRC_FOLDER)/myPS.c -o $(BUILD_FOLDER)/myPS $(LDFLAGS)

$(BUILD_FOLDER)/wordCount: $(SRC_FOLDER)/wordCount.c | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $(SRC_FOLDER)/wordCount.c -o $(BUILD_FOLDER)/wordCount $(LDFLAGS)

$(BUILD_FOLDER)/createFold: $(SRC_FOLDER)/createFold.c | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $(SRC_FOLDER)/createFold.c -o $(BUILD_FOLDER)/createFold $(LDFLAGS)

$(BUILD_FOLDER)/removeFold: $(SRC_FOLDER)/removeFold.c | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $(SRC_FOLDER)/removeFold.c -o $(BUILD_FOLDER)/removeFold $(LDFLAGS)

ex1_1: $(BUILD_FOLDER)/myPS
	./$(BUILD_FOLDER)/myPS

ex1_2: $(BUILD_FOLDER)/wordCount
	./$(BUILD_FOLDER)/wordCount

ex1_3: $(BUILD_FOLDER)/createFold
	./$(BUILD_FOLDER)/createFold Group 5

ex1_4: $(BUILD_FOLDER)/removeFold
	./$(BUILD_FOLDER)/removeFold Group 5

clean:
	rm -rf $(BUILD_FOLDER)