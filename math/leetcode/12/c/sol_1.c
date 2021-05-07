/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 12. Integer to Roman
 * @date 2021.05.07
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <string.h>

char* intToRoman(int num) {
    const int units[13] = {1000, 900, 500, 400, 100, 90, 50,
                           40,   10,  9,   5,   4,   1};
    const char* const symbol[13] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                    "XL", "X",  "IX", "V",  "IV", "I"};
    const int symlen[13] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1};

    char* s = malloc(sizeof(char) * 200);
    char* p = s;

    int idx = 0;

    while (num > 0) {
        for (int i = idx; i < 13; i++) {
            if (num >= units[i]) {
                idx = i;
                break;
            }
        }

        num -= units[idx];
        strncpy(p, symbol[idx], symlen[idx]);
        p += symlen[idx];
    }

    *p = '\0';

    return s;
}
