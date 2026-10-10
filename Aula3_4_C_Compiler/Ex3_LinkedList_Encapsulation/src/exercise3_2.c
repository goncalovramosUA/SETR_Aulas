#include <unity.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void setUp(void)
{
    /* This is run before EACH test */ 
    return;
}

void tearDown(void)
{
    /* This is run before EACH test */ 
    return;
}

void test_insertValue(void)
{
    /* Test inserting first value */
    struct Node* head = NULL;
    TEST_ASSERT_NULL(head);
    insertValue(&head, 30);
    TEST_ASSERT_EQUAL_INT(30, (*head).value);
    TEST_ASSERT_NOT_NULL(head);

    /* Test inserting a second value */
    insertValue(&head, 20);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(20, (*head).value);
    TEST_ASSERT_NOT_NULL((*head).next);
    TEST_ASSERT_EQUAL_INT(30, (*(*head).next).value);

    /* Free memory - Without deleteValue() because not tested YET*/
    struct Node* second = (*head).next;
    free(head);                         
    free(second);                       
}

void test_deleteValue(void)
{
    /* Deleting last number */
    struct Node* head = NULL;
    insertValue(&head, 30);
    insertValue(&head, 20);
    TEST_ASSERT_EQUAL_INT(20, (*head).value);
    deleteValue(&head, 20);
    TEST_ASSERT_EQUAL_INT(30, (*head).value);
    TEST_ASSERT_NOT_NULL(head);

    /* Deleting middle number */
    insertValue(&head, 1);
    insertValue(&head, 2);
    insertValue(&head, 3);
    TEST_ASSERT_EQUAL_INT(3, (*head).value);
    TEST_ASSERT_EQUAL_INT(2, (*(*head).next).value);
    deleteValue(&head, 2);
    TEST_ASSERT_EQUAL_INT(3, (*head).value);
    TEST_ASSERT_EQUAL_INT(1, (*(*head).next).value);

    /* Deleting non-existing number */
    deleteValue(&head, 99);

    /* Free memory */
    deleteValue(&head, 3);
    deleteValue(&head, 1);
    deleteValue(&head, 30);

}

void test_printLinkedList(void)
{
    struct Node* head = NULL;
    
    /* Print empty list */
    printLinkedList(head); 
    
    /* Print populated list */
    insertValue(&head, 30);
    insertValue(&head, 20);
    insertValue(&head, 10);
    insertValue(&head, 15);
    printLinkedList(head);

    /* Free memory */
    deleteValue(&head, 30);
    deleteValue(&head, 20);
    deleteValue(&head, 10);
    deleteValue(&head, 15);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_insertValue);
    RUN_TEST(test_deleteValue);
    RUN_TEST(test_printLinkedList);

    return UNITY_END();
}