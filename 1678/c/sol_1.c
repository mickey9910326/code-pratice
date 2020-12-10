/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 1678. Goal Parser Interpretation
 * @date 2020.12.10
 *
 * Time Complexity: O(n)
 */

#include <stdlib.h>

/**
 * 1 <= command.length <= 100
 * command consists of "G", "()", and/or "(al)" in some order.
 */
char* interpret(char* command) {
    char ch;

    char* s = malloc(100);
    char ch = 0;

    int idx = 0;
    int brackets_flag = 1;
    int al_flag = 1;

    for (int i = 0; command[i] != 0; i++) {
        ch = command[i];

        if (ch == 'G') {
            s[idx] = 'G';
            idx++;
        }
        else if (ch == '(') {
        }
        else if (ch == ')') {
            if (al_flag) {
                s[idx + 1] = 'a';
                s[idx + 2] = 'l';
                idx += 2;
            }
            else {
                s[idx] = 'o';
                idx++;
            }
        }
        else if (ch == 'a') {
            al_flag = 1;
        }
        else if (ch == 'l') {
        }
    }
}
