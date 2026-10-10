#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

void insertValue(Node** head, int value);
void deleteValue(Node** head, int value);
void printLinkedList(Node* head);


int main(void){

    Node* head = NULL;
    printLinkedList(head);

    /* Inserting values */ 
    insertValue(&head, 10);
    insertValue(&head, 20);
    insertValue(&head, 30);
    printLinkedList(head);
    
    deleteValue(&head, 20); /* Apaga do meio (o 20): 30 liga diretamente ao 10 */
    printLinkedList(head);
    
    deleteValue(&head, 30); /* Apaga a nova cabeça (o 30): a cabeça passa a ser o 10 */
    printLinkedList(head);
    
    deleteValue(&head, 99); /* Tentativa de apagar um valor inexistente */
    deleteValue(&head, 10);
    printLinkedList(head);
    

    return 0;   
}


void insertValue(Node** head, int val) /* insertValue em modo LIFO (Last In Fist Out) */
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