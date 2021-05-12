/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 138. Copy List with Random Pointer
 * @date 2021.05.12
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

#include <stdbool.h>
#include <stdlib.h>
// #include <uthash.h>

struct Node* new_node(int val) {
    struct Node* p = malloc(sizeof(struct Node));
    p->val = val;
    p->next = NULL;
    p->random = NULL;
    return p;
}

struct NodeHashItem {
    void* key;
    void* val;
    UT_hash_handle hh; /* makes this structure hashable */
};

struct NodeHashItem* NodeMap = NULL;

void node_map_add(void* k, void* v) {
    struct NodeHashItem* p = malloc(sizeof(struct NodeHashItem));
    p->key = k;
    p->val = v;
    p->val = v;
    HASH_ADD_PTR(NodeMap, key, p);
}

void* node_map_find_val(void* node) {
    struct NodeHashItem* p;

    HASH_FIND_PTR(NodeMap, &node, p);
    if (p) {
        return p->val;
    }
    else {
        return NULL;
    }
}

void print_nodes() {
    struct NodeHashItem* p;

    for (p = NodeMap; p != NULL; p = (struct NodeHashItem*)(p->hh.next)) {
        printf("%p %p\n", p->key, p->val);
    }
}

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node dummy;
    struct Node* new = &dummy;
    struct Node* curr = head;
    struct Node* p = head;

    int idx = 0;

    curr = head;
    while (curr) {
        new->next = new_node(curr->val);
        node_map_add(curr, new->next);
        curr = curr->next;
        new = new->next;
        idx++;
    }

    curr = head;
    new = dummy.next;
    while (curr) {
        new->random = node_map_find_val(curr->random);

        curr = curr->next;
        new = new->next;
    }

    return dummy.next;
}
