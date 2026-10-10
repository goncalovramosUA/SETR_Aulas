#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/* Para fazer corretamente a definição do Node abaixo deveria ser feita apenas no .C 
    Esse aproach daria erro de compilação, pelo que é necessário utilizar as funções get
    comentadas abaixo. A segunda opção seria a mais correta para encapsular a linked_list*/

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void insertValue(Node** head, int value);
void deleteValue(Node** head, int value);
void printLinkedList(Node* head);

/*
int getNodeValue(const Node* node);
Node* getNextNode(const Node* node);
*/

#endif