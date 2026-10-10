#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*
typedef struct Node{
    int value;
    struct Node* next;
}Node; */

void insertValue(Node** head, int val) /* insertValue() em modo LIFO (Last In Fist Out) */ 
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL){
        printf("Erro: falha na alocação de memória!\n");
        return;
    }

    (*n).value = val;
    (*n).next = *head;

    *head = n;

    return;
}

void deleteValue(Node** head, int val)
{
    if (*head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    Node* current = *head;
    Node* previous = NULL;
    
    if((*current).value == val)
    {
        *head = (*current).next;
        free(current);
        printf("Valor %d removido com sucesso.\n", val);
        return;
    }

    while (current != NULL && (*current).value != val) {
        previous = current;        
        current = (*current).next; 
    }

    if (current == NULL) {
        printf("Valor %d não encontrado na lista.\n", val);
        return;
    }

    (*previous).next = (*current).next;

    free(current);
    printf("Valor %d removido com sucesso.\n", val);

}

void printLinkedList(Node* head)
{
    Node* current = head;

    printf("A linked list é composta por: ");
    while (current != NULL) {
        printf("%d ", (*current).value);
        current = (*current).next;
    }
    printf("NULL\n");
}