/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 707. Design Linked List
 * @date 2021.05.05
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

typedef struct {
    struct ListNode* head;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* p = malloc(sizeof(MyLinkedList));
    p->head = NULL;

    return p;
}

/** Get the value of the index-th node in the linked list. If the index is
 * invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    struct ListNode* curr = obj->head;
    for (int i = 0; i < index && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr) {
        return curr->val;
    }
    else {
        return -1;
    }
}

/** Add a node of value val before the first element of the linked list. After
 * the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct ListNode* p = malloc(sizeof(struct ListNode));
    p->next = obj->head;
    p->val = val;
    obj->head = p;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct ListNode dummy = {.next = obj->head};

    struct ListNode* curr = &dummy;
    struct ListNode* p = malloc(sizeof(struct ListNode));
    p->next = NULL;
    p->val = val;

    while (curr->next) {
        curr = curr->next;
    }
    curr->next = p;
    obj->head = dummy.next;
}

/** Add a node of value val before the index-th node in the linked list. If
 * index equals to the length of linked list, the node will be appended to the
 * end of linked list. If index is greater than the length, the node will not be
 * inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    struct ListNode dummy = {.next = obj->head};
    struct ListNode* curr = &dummy;

    for (int i = 0; i < index && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr) {
        struct ListNode* p = malloc(sizeof(struct ListNode));
        p->val = val;
        p->next = curr->next;
        curr->next = p;
        obj->head = dummy.next;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    struct ListNode dummy = {.next = obj->head};
    struct ListNode* curr = &dummy;

    for (int i = 0; i < index && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr->next) {
        curr->next = curr->next->next;
        obj->head = dummy.next;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = obj->head;
    while (curr) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/
