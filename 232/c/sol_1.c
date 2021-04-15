/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 232. Implement Queue using Stacks
 * @date 2020.04.15
 *
 */

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int idx;
    int data[100];
} Stack;

Stack* stackCreate() {
    Stack* obj = malloc(sizeof(Stack));
    obj->idx = 0;
    return obj;
}

void stackPush(Stack* obj, int x) {
    obj->data[obj->idx] = x;
    obj->idx++;
}

int stackPop(Stack* obj) {
    int res = obj->data[obj->idx];
    obj->idx--;
    return res;
}

int stackPeek(Stack* obj) {
    return obj->data[obj->idx];
}

bool stackEmpty(Stack* obj) {
    if (obj->idx != 0) {
        return true;
    }
    else {
        return false;
    }
}

void stackFree(Stack* obj) {
    free(obj);
}

typedef struct {
    Stack* s1;
    Stack* s2;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate() {
    MyQueue* obj = malloc(sizeof(MyQueue));
    obj->s1 = stackCreate();
    obj->s2 = stackCreate();
    return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->s1, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int v;
    int res;
    while (!stackEmpty(obj->s1)) {
        v = stackPop(obj->s1);
        stackPush(obj->s2, v);
    }

    res = stackPop(obj->s2);

    while (!stackEmpty(obj->s2)) {
        v = stackPop(obj->s2);
        stackPush(obj->s1, v);
    }
    return res;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    int v;
    int res;
    while (!stackEmpty(obj->s1)) {
        v = stackPop(obj->s1);
        stackPush(obj->s2, v);
    }

    res = stackPop(obj->s2);
    stackPush(obj->s1, res);

    while (!stackEmpty(obj->s2)) {
        v = stackPop(obj->s2);
        stackPush(obj->s1, v);
    }
    return res;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(obj->s1);
}

void myQueueFree(MyQueue* obj) {
    free(obj->s1);
    free(obj->s2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
