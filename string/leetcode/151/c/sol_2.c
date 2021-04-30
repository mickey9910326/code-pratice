/**
 * @file sol_2.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 151. Reverse Words in a String
 * @date 2021.04.26
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Refer to
 * https://leetcode.com/problems/reverse-words-in-a-string/discuss/737525/C-Language-O(1)-space-with-comments
 *
 * 1. remove leading, trailing and extra spaces between words.
 * 2. reverse the whole string, the each word itself reversed as well.
 * 3. revsese each word to oringinal order.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char* s, int len) {
    char tmp;
    int l = 0;        // left index
    int r = len - 1;  // right index

    while (r > l) {
        tmp = s[r];
        s[r] = s[l];
        s[l] = tmp;

        l++;
        r--;
    }
}

char* reverseWords(char* s) {
    if (s == NULL) {
        return s;
    }

    int len = strlen(s);

    if (len == 0) {
        return s;
    }

    char pre_ch = ' ';
    int i;
    int j;

    // 1. remove leading, trailing and extra spaces between words.
    i = 0;  // read index
    j = 0;  // write index
    for (i = 0; i < len; i++) {
        if (s[i] == ' ' && pre_ch == ' ') {
            // multi space, do nothing
        }
        else {
            s[j] = s[i];
            j++;
        }
        pre_ch = s[i];
    }

    if (s[j - 1] == ' ') {
        j--;
    }
    s[j] = '\0';

    if (len == 0 || len == 1) {
        // len = 0 or len =1  no need to do further
        return s;
    }

    // 2. reverse the whole string, the each word itself reversed as well.
    len = strlen(s);
    reverseString(s, len);

    // 3. revsese each word to oringinal order.
    i = 0;  // end index of a word
    j = 0;  // start index of a word
    while (i < len) {
        if (s[i] == ' ') {
            reverseString(s + j, i - j);
            j = i + 1;
        }
        i++;
    }
    reverseString(s + j, i - j);

    return s;
}
