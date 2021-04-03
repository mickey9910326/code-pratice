/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 1446. Consecutive Characters
 * @date 2021.04.03
 *
 */

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * @brief
 *
 * @param s
 * @return int
 */
int maxPower(char* s) {
    int len = 1;
    int max = 0;
    int pre_ch = 0;

    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == pre_ch) {
            len++;
        }
        else {
            pre_ch = s[i];
            len = 1;
        }
        max = MAX(max, len);
    }

    return max;
}
