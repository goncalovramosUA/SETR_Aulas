# Gonçalo Ramos, Oct/2026
# Adapted from Paulo Pedreiras

MODULE_NAME = word_list

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
SRC_FILES_PROG = $(SRC_FOLDER)/$(MODULE_NAME).c
SRC_FILES_TEST = $(UNITY_ROOT)/src/unity.c \
				$(SRC_FOLDER)/$(MODULE_NAME).c \
            	$(TEST_FOLDER)/test_$(MODULE_NAME).c

INC_DIRS_PROG = -I$(SRC_FOLDER)
INC_DIRS_TEST = -I$(SRC_FOLDER) -I$(TEST_FOLDER) -I$(UNITY_ROOT)/src

TARGET_TEST_WORDLIST = $(BUILD_FOLDER)/$(MODULE_NAME)


.PHONY: all default test clean


all: default

default: word_list

$(TARGET_TEST_WORDLIST): $(SRC_FILES_TEST) | $(BUILD_FOLDER)
	$(CC) $(CFLAGS) $(INC_DIRS_TEST) $(SRC_FILES_TEST) -o $(TARGET_TEST_WORDLIST) $(LDFLAGS)

# Test Word_List
word_list: $(TARGET_TEST_WORDLIST)
	./$(TARGET_TEST_WORDLIST)

clean:
	rm -rf $(BUILD_FOLDER)