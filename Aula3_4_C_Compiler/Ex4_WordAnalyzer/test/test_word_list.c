#include <unity.h>
#include "word_list.h"

void setUp(void){return;}
void tearDown(void){return;}


/* --- Testing getNumAppearance(); --- */
void test_getNumAppearance_should_return_zero_on_empty_list(void){
    WordList* head = NULL;
    int number = getNumAppearance(head, "test");
    TEST_ASSERT_EQUAL_INT(0, number);
}

void test_getNumAppearance_should_return_zero_when_word_is_NULL(void){
    WordList* head = NULL;
    insertWord(&head, "testWord");
    int number = getNumAppearance(head, NULL);
    TEST_ASSERT_EQUAL_INT(0, number);

     /* Cleaning Up WordList */
    freeWordList(&head);
}

void test_getNumAppearance_should_return_correct_number_in_an_one_element_list(void){
    WordList* head = NULL;
    insertWord(&head, "testWord");
    insertWord(&head, "testWord");
    insertWord(&head, "testWord");
    insertWord(&head, "testWord");
    int number = getNumAppearance(head, "testWord");
    TEST_ASSERT_EQUAL_INT(4, number);
    
    /* Cleaning Up WordList */
    freeWordList(&head);
}

void test_getNumAppearance_should_return_correct_number_in_a_populated_list(void){
    WordList* head = NULL;
    insertWord(&head, "testWord1");
    insertWord(&head, "testWord2");
    insertWord(&head, "testWord3");
    insertWord(&head, "testWord1");
    int number = getNumAppearance(head, "testWord1");
    TEST_ASSERT_EQUAL_INT(2, number);
    
    /* Cleaning Up WordList */
    freeWordList(&head);
}

/* --- Testing insertWord(); --- */
void test_insertWord_should_not_crash_when_head_pointer_is_null(void){
    WordList* head = NULL;
    insertWord(&head, "testWord");
    TEST_PASS();
}

void test_insertWord_should_not_crash_when_word_is_NULL(void){
    WordList* head = NULL;
    insertWord(&head, NULL);
    TEST_ASSERT_NULL(head);
}

void test_insertWord_should_insert_successfully_on_empty_list(void) {
    WordList *head = NULL;
    insertWord(&head, "testWord");
    
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(1, getNumAppearance(head, "testWord"));

    /* Cleaning Up WordList */
    freeWordList(&head);
}

void test_insertWord_should_insert_successfully_on_populated_list(void) {
    WordList *head = NULL;
    insertWord(&head, "testWord1");
    insertWord(&head, "testWord2");
    insertWord(&head, "testWord1");
    
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(2, getNumAppearance(head, "testWord1"));
    TEST_ASSERT_EQUAL_INT(1, getNumAppearance(head, "testWord2"));

    /* Cleaning Up WordList */
    freeWordList(&head);
}

/* --- Testing freeWordList(); --- */
void test_freeWordList_should_handle_empty_list_safely(void){
    WordList *head = NULL;
    freeWordList(&head);
    TEST_ASSERT_NULL(head);
}

void test_freeWordList_should_clean_multiple_nodes_and_set_head_to_null(void){
    WordList *head = NULL;
    insertWord(&head, "testWord1");
    insertWord(&head, "testWord2");
    TEST_ASSERT_NOT_NULL(head);

    freeWordList(&head);
    TEST_ASSERT_NULL(head);

}

/* --- Testing printWordList(); --- */
void test_printWordList_should_print_successfully_on_empty_list(void) {
    WordList *head = NULL;
    printWordList(head);
    TEST_PASS();
}

void test_printWordList_should_print_successfully_populated_list(void) {
    WordList *head = NULL;
    insertWord(&head, "populated");
    insertWord(&head, "list");
    insertWord(&head, "returning");
    insertWord(&head, "list");
    insertWord(&head, "list");
    insertWord(&head, "printing");
    insertWord(&head, "testWord");

    printWordList(head);
    TEST_PASS();

    /* Cleaning Up WordList */
    freeWordList(&head);
}

/* --- Testing sortWordListByFrequency(); --- */
void test_sortWordListByFrequency_handle_empty_list_safely(void) {
    WordList *head = NULL;
    sortWordListByFrequency(head);
    TEST_ASSERT_NULL(head);
}

void test_sortWordListByFrequency_handle_one_element_list_safely(void) {
    WordList *head = NULL;
    insertWord(&head, "testWord");
    sortWordListByFrequency(head);
    TEST_ASSERT_NOT_NULL(head);
    TEST_ASSERT_EQUAL_INT(1, getNumAppearance(head, "testWord"));

    /* Cleaning Up WordList */
    freeWordList(&head);
}

void test_sortWordListByFrequency_handle_populated_list_safely(void) {
    WordList *head = NULL;
    insertWord(&head, "common");
    insertWord(&head, "frequent");
    insertWord(&head, "veryRare");
    insertWord(&head, "common");
    insertWord(&head, "frequent");
    insertWord(&head, "common");
    insertWord(&head, "frequent");
    insertWord(&head, "common");
    insertWord(&head, "common");
    insertWord(&head, "rare");
    insertWord(&head, "rare");
    printWordList(head);

    sortWordListByFrequency(head);
    printWordList(head);
    TEST_ASSERT_EQUAL_INT(5, getNumAppearance(head, "common"));
    TEST_ASSERT_EQUAL_INT(3, getNumAppearance(head, "frequent"));
    TEST_ASSERT_EQUAL_INT(2, getNumAppearance(head, "rare"));
    TEST_ASSERT_EQUAL_INT(1, getNumAppearance(head, "veryRare"));

    freeWordList(&head);
}


/* MAIN LOOP */

int main(void){

    UNITY_BEGIN();

    /* Testing invalid entries and empty lists */
    RUN_TEST(test_insertWord_should_not_crash_when_head_pointer_is_null);
    RUN_TEST(test_insertWord_should_not_crash_when_word_is_NULL);
    RUN_TEST(test_getNumAppearance_should_return_zero_on_empty_list);
    RUN_TEST(test_freeWordList_should_handle_empty_list_safely);
    RUN_TEST(test_printWordList_should_print_successfully_on_empty_list);
    RUN_TEST(test_sortWordListByFrequency_handle_empty_list_safely);

    /* Basic insetion and verifying with getNumAppearance */
    RUN_TEST(test_insertWord_should_insert_successfully_on_empty_list);
    RUN_TEST(test_insertWord_should_insert_successfully_on_populated_list);
    RUN_TEST(test_getNumAppearance_should_return_zero_when_word_is_NULL);
    RUN_TEST(test_getNumAppearance_should_return_correct_number_in_an_one_element_list);
    RUN_TEST(test_getNumAppearance_should_return_correct_number_in_a_populated_list);

    /* sortWordListByFrequency(); behavior with 1 element */
    RUN_TEST(test_sortWordListByFrequency_handle_one_element_list_safely);

    /* Complete operations with multiple elements */
    RUN_TEST(test_printWordList_should_print_successfully_populated_list);
    RUN_TEST(test_sortWordListByFrequency_handle_populated_list_safely);
    RUN_TEST(test_freeWordList_should_clean_multiple_nodes_and_set_head_to_null);

    return UNITY_END();
}