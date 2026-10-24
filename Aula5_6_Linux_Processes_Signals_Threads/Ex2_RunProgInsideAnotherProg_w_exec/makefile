# Compiler & Flags
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra
LDFLAGS = -lm

# PATHS
SRC_FOLDER = src
BUILD_FOLDER = build


.PHONY: all default test clean ex2_1 ex2_2 ex2_3 ex2_4

all: default

default: ex2_1

$(BUILD_FOLDER):
	mkdir -p $(BUILD_FOLDER)

$(BUILD_FOLDER)/myPS_exec: $(SRC_FOLDER)/myPS_exec.c | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $(SRC_FOLDER)/myPS_exec.c -o $(BUILD_FOLDER)/myPS_exec $(LDFLAGS)

$(BUILD_FOLDER)/wordCount_exec: $(SRC_FOLDER)/wordCount_exec.c | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $(SRC_FOLDER)/wordCount_exec.c -o $(BUILD_FOLDER)/wordCount_exec $(LDFLAGS)

$(BUILD_FOLDER)/createFold_exec: $(SRC_FOLDER)/createFold_exec.c | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $(SRC_FOLDER)/createFold_exec.c -o $(BUILD_FOLDER)/createFold_exec $(LDFLAGS)

$(BUILD_FOLDER)/removeFold_exec: $(SRC_FOLDER)/removeFold_exec.c | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $(SRC_FOLDER)/removeFold_exec.c -o $(BUILD_FOLDER)/removeFold_exec $(LDFLAGS)

ex2_1: $(BUILD_FOLDER)/myPS_exec
	./$(BUILD_FOLDER)/myPS_exec

ex2_2: $(BUILD_FOLDER)/wordCount_exec
	./$(BUILD_FOLDER)/wordCount_exec

ex2_3: $(BUILD_FOLDER)/createFold_exec
	./$(BUILD_FOLDER)/createFold_exec Group 5

ex2_4: $(BUILD_FOLDER)/removeFold_exec
	./$(BUILD_FOLDER)/removeFold_exec Group 5

clean:
	rm -rf $(BUILD_FOLDER)