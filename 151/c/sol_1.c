/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 151. Reverse Words in a String
 * @date 2021.04.26
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * Use two index to view the input string from the end.
 * Index ws detect the start of a word.
 * Index we detect the end of a word.
 * If a word detected, than add the word to the new string.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* reverseWords(char* s) {
    if (s == NULL) {
        return s;
    }

    int len = strlen(s);

    if (len == 0) {
        return s;
    }

    char* res = malloc(sizeof(char) * (len + 1));
    int res_idx = 0;

    int we = len - 1;  // end index of word
    int ws = len - 1;  // start index of word

    while (ws >= 0 && we >= 0) {
        if (s[we] == ' ') {
            we--;
            ws = we;
        }
        else if (s[ws] != ' ') {
            ws--;
        }
        else if (s[ws] == ' ') {
            for (int i = ws + 1; i <= we; i++) {
                res[res_idx] = s[i];
                res_idx++;
            }
            res[res_idx] = ' ';
            res_idx++;
            we = ws;
        }
    }

    if (we >= 0) {
        // add the start word of input s
        for (int i = 0; i <= we; i++) {
            res[res_idx] = s[i];
            res_idx++;
        }
        res[res_idx] = '\0';
    }
    else {
        // the start of input s is ' ', not a word
        // replace ' ' to '\0' at the end of res string
        res[res_idx - 1] = '\0';
    }

    return res;
}
