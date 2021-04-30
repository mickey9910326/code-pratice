/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 224. Basic Calculator
 * @date 2020.12.10
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <stdlib.h>

#define OPERATOR_NULL 0
#define OPERATOR_PLUS '+'
#define OPERATOR_MINUS '-'

typedef struct node {
    int operator;
    long int num;
    struct node* pre;   ///< previous
    struct node* next;  ///< next
} node_t;

node_t* new_node(int op, int num) {
    node_t* p = (node_t*)malloc(sizeof(node_t));

    p->operator= op;
    p->num = num;
    p->pre = 0;
    p->next = 0;

    return p;
}

int calculate(char* s) {
    long int num = 0;

    // always add "0+" in start
    node_t* root = new_node(OPERATOR_PLUS, 0);
    node_t* p = root;

    while (*s != '\0') {
        switch (*s) {
            case '+':
            case '-': {
                if (p->operator== OPERATOR_PLUS) {
                    p->num += num;
                }
                else if (p->operator== OPERATOR_MINUS) {
                    p->num -= num;
                }
                p->operator= *s;

                num = 0;
                break;
            }
            case '(': {
                // add a new node
                p->next = new_node(OPERATOR_PLUS, 0);
                p->next->pre = p;
                p = p->next;
                break;
            }
            case ')': {
                if (p->operator== OPERATOR_PLUS) {
                    p->num += num;
                }
                else if (p->operator== OPERATOR_MINUS) {
                    p->num -= num;
                }
                p->operator= OPERATOR_NULL;
                num = 0;

                num = p->num;
                p = p->pre;

                // destory node
                free(p->next);
                p->next = NULL;

                if (p->operator== OPERATOR_PLUS) {
                    p->num += num;
                }
                else if (p->operator== OPERATOR_MINUS) {
                    p->num -= num;
                }
                num = 0;
                p->operator= OPERATOR_NULL;
                break;
            }
            case ' ': {
                break;
            }
            default: {
                // The input string is always legal,
                // so the other case is digit.
                num = num * 10 + *s - '0';
                break;
            }
        }
        s++;
    }

    if (p->operator== OPERATOR_PLUS) {
        p->num += num;
    }
    else if (p->operator== OPERATOR_MINUS) {
        p->num -= num;
    }
    num = p->num;
    free(p);

    return num;
}
