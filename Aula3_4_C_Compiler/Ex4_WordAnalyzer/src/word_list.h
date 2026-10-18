/* Mange all data retrived by file_utils */

#ifndef WORD_LIST_H
#define WORD_LIST_H

typedef struct WordList WordList;

int getNumAppearance(const WordList *head, const char *word);
void insertWord(WordList **head, const char *word);
void freeWordList(WordList **head);
void printWordList(const WordList *head);
void sortWordListByFrequency(WordList *head);

#endif