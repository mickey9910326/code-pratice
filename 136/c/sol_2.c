/**
 * @file sol_2.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief 136. Single Number
 * @date 2020.12.16
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 */

int singleNumber(int* nums, int numsSize) {
    int* arr = malloc(sizeof(int) * numsSize);
    int i;
    int j;
    int ret;

    for (i = 0; i < numsSize; i++) {
        arr[i] = nums[i];
    }

    for (i = 0; i < numsSize; i++) {
        if (arr[i] == (-3e4 - 1)) {
            continue;
        }

        for (j = i + 1; j < numsSize; j++) {
            if (arr[i] == arr[j]) {
                arr[i] = (-3e4 - 1);
                arr[j] = (-3e4 - 1);
                break;
            }
        }

        if (j == numsSize) {
            ret = arr[i];
            break;
        }
    }

    free(arr);

    return ret;
}
