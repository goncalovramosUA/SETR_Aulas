#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "word_list.h"

struct WordList {
    char *word;
    int numAppearance;
    struct WordList *next;
};

int getNumAppearance(const WordList *head, const char *word) {
    
    /* Verify if arguments are valid */
    if (head == NULL || word == NULL) {
        return 0;
    }

    const WordList *current = head;

    /* Check where word passed in the function argument is in the WordList */
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) { /* If it finds the word, returns the numAppearance */
            return current->numAppearance;
        }
        current = current->next;
    }

    return 0;
}

void insertWord(WordList **head, const char *word) {

    /* Verify if arguments are valid */ 
    if (head == NULL || word == NULL) {
        return;
    }

    WordList *current = *head;

    /* Search if word already exists. If exists, increases numAppearance */ 
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->numAppearance++;
            return;
        }
        current = current->next;
    }

    /* If doesnt exist, handles the creation of new word */
    WordList *new_word = (WordList *)malloc(sizeof(WordList));
    if (new_word == NULL) {
        perror("Erro na alocação de memória para o nó");
        return;
    }

    /* Allocate and copy the word (strdup makes the malloc + strcpy) */ 
    new_word->word = (char *)malloc(strlen(word) + 1);
    if (new_word->word == NULL) {
        free(new_word);
        return;
    }
    strcpy(new_word->word, word);
    
    new_word->numAppearance = 1;

    new_word->next = *head;
    *head = new_word;
}

void freeWordList(WordList **head) {
    
    /* Verify if exists a list */ 
    if (head == NULL || *head == NULL) {
        return;
    }

    /* Free all space from WordList */
    WordList *current = *head;
    while (current != NULL) {
        WordList *next_node = current->next;
        free(current->word);
        free(current);       
        current = next_node;
    }

    *head = NULL;
}

void printWordList(const WordList *head) {

    /* Verify the list is empty */ 
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    const WordList *current = head;
    printf("Word frequency:\n");
    while (current != NULL) {
        printf("\"%s\": %d\n", current->word, current->numAppearance);
        current = current->next;
    }
}

void sortWordListByFrequency(WordList *head) {
    
    /* Verify if WordList in argument is valid or a list composed by 1 element*/
    if (head == NULL || head->next == NULL) {
        return;
    }

    bool swapped;
    WordList *current;

    do {
        swapped = false;
        current = head;

        /* Bubble Sorting the WordList, least frequent words are closer to the NULL (tail) */
        while (current->next != NULL) {

            /* Instead of switch the WordList node itself, dealing with pointers, 
               this if statement is switching the contents of two WordList Node */
            if (current->numAppearance < current->next->numAppearance) {
                
                /* Switch the numAppearance */
                int tempN = current->numAppearance;
                current->numAppearance = current->next->numAppearance;
                current->next->numAppearance = tempN;

                /* Switch the string pointers */
                char *tempW = current->word;
                current->word = current->next->word;
                current->next->word = tempW;

                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}