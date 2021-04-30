/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 338. Counting Bits
 * @date 2020.12.22
 *
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    *returnSize = num + 1;
    int* ret = (int*)malloc(sizeof(int) * (*returnSize));

    ret[0] = 0;

    for (int i = 1; i < *returnSize; i++) {
        ret[i] = ret[i / 2] + (i & 1);
    }

    return ret;
}

// 0    0
// 1    1
// 2~3  1, 2
// 4~7  1, 2, 2, 3
// 8~15 1, 2, 2, 3, 3, 3, 3, 4
