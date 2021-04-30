/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 20. Valid Parentheses
 * @date 2020.04.04
 *
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isValid(char* s) {
    int len = strlen(s);
    char* p = malloc(sizeof(char) * len);
    int idx_s = 0;
    int idx_p = 0;
    char ch;

    for (int i = 0; i < len; i++) {
        ch = s[i];
        switch (ch) {
            case '(':
            case '[':
            case '{':
                p[idx_p] = ch;
                idx_p++;
                break;
            case ')':
                if (idx_p - 1 >= 0 && p[idx_p - 1] == '(') {
                    idx_p--;
                }
                else {
                    return false;
                }
                break;
            case ']':
                if (idx_p - 1 >= 0 && p[idx_p - 1] == '[') {
                    idx_p--;
                }
                else {
                    return false;
                }
                break;
            case '}':
                if (idx_p - 1 >= 0 && p[idx_p - 1] == '{') {
                    idx_p--;
                }
                else {
                    return false;
                }
                break;
            default:
                return false;
        }
    }

    if (idx_p == 0) {
        return true;
    }
    else {
        return false;
    }
}
