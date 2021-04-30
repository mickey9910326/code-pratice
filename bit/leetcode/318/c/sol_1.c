/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 318. Maximum Product of Word Lengths
 * @date 2020.12.24
 *
 * Time Limit Exceeded. :(
 *
 * Time Complexity: O(n^2 * m^2)
 *   n is length of words.
 *   m is avg. length of a word in words.
 * Space Complexity: O(1)
 */

#include <stdbool.h>

int maxProduct(char **words, int wordsSize) {
    int idx1;
    int idx2;
    bool passed;
    int product = 0;
    int max = 0;

    // iter for word in words
    for (int i = 0; i < wordsSize; i++) {
        // exception for null string
        if (words[i][0] == '\0') {
            continue;
        }

        for (int j = i + 1; j < wordsSize; j++) {
            // exception for null string
            if (words[j][0] == '\0') {
                continue;
            }

            idx1 = 0;
            idx2 = 0;
            passed = true;

            while (passed) {
                if (words[i][idx1] == words[j][idx2]) {
                    passed = false;
                }

                idx2++;
                if (words[j][idx2] == '\0') {
                    idx1++;
                    if (words[i][idx1] == '\0') {
                        break;
                    }
                    idx2 = 0;
                }
            }

            if (passed) {
                product = idx1 * idx2;
                if (product > max) {
                    max = product;
                }
            }
        }
    }

    return max;
}
