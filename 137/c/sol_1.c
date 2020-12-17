/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief 137. Single Number II
 * @date 2020.12.16
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 */

typedef struct node {
    int val;
    int count;
    struct node* next;
} node_t;

node_t* new_node(int val) {
    node_t* p = malloc(sizeof(node_t));
    p->val    = val;
    p->count  = 1;
    p->next   = NULL;
    return p;
}

int singleNumber(int* nums, int numsSize) {
    node_t* head = new_node(nums[0]);
    node_t* p;

    int i;
    int founded;
    int ret = 0;

    for (i = 1; i < numsSize; i++) {
        founded = 0;
        p       = head;

        while (1) {
            if (p->val == nums[i]) {
                p->count++;
                founded = 1;
                break;
            }

            if (p->next == NULL) {
                p->next = new_node(nums[i]);
                break;
            }
            p = p->next;
        }
    }

    for (p = head; p != NULL; p = p->next) {
        if (p->count == 1) {
            ret = p->val;
        }
    }

    return ret;
}
