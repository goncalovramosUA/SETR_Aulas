
# Gonçalo Ramos, Oct/2026
# Adapted from Paulo Pedreiras

MODULE_NAME = linked_list

# PATHS
UNITY_ROOT = ../../Unity
SRC_FOLDER = src
TEST_FOLDER = test
BUILD_FOLDER = build

# Compiler & Flags
CC = gcc
CFLAGS = -std=c89 -Wall -Wextra
LDFLAGS = -lm

# Source Files, Include Directories & Executable Outputs
SRC_FILES_PROG = $(SRC_FOLDER)/exercise3_1.c
SRC_FILES_TEST = $(UNITY_ROOT)/src/unity.c \
            	$(SRC_FOLDER)//exercise3_2.c \
            	$(TEST_FOLDER)/$(MODULE_NAME).c

INC_DIRS_PROG = -I$(SRC_FOLDER)
INC_DIRS_TEST = -I$(SRC_FOLDER) -I$(TEST_FOLDER) -I$(UNITY_ROOT)/src

TARGET_PROG = $(BUILD_FOLDER)/$(MODULE_NAME)_ex1
TARGET_TEST = $(BUILD_FOLDER)/test_$(MODULE_NAME)_ex2


.PHONY: all default test clean


all: default

default: ex1

$(TARGET_PROG): $(SRC_FILES_PROG) | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $(INC_DIRS_PROG) $(SRC_FILES_PROG) -o $(TARGET_PROG) $(LDFLAGS)

$(TARGET_TEST): $(SRC_FILES_TEST) | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $(INC_DIRS_TEST) $(SRC_FILES_TEST) -o $(TARGET_TEST) $(LDFLAGS)

# prog
ex1: $(TARGET_PROG)
	./$(TARGET_PROG)

# test
ex2: $(TARGET_TEST)
	./$(TARGET_TEST)

clean:
	rm -rf $(BUILD_FOLDER)