/**
 * @file sol_2.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 318. Maximum Product of Word Lengths
 * @date 2020.12.24
 *
 * Use each bit in intger to store if a letter (a~z) found in a word.
 *
 * Example:
 *   bit 0:
 *     - 1 means 'a' is founded in word.
 *     - 0 means 'a' is unfounded in word.
 *   bit 1:
 *     - 1 means 'b' is founded in word.
 *     - 0 means 'b' is unfounded in word.
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int maxProduct(char** words, int wordsSize) {
    int product = 0;
    int max = 0;

    int* arr = malloc(sizeof(int) * wordsSize);

    for (int i = 0; i < wordsSize; i++) {
        arr[i] = 0;
        for (char* p = words[i]; *p != '\0'; p++) {
            arr[i] |= 1 << (*p - 'a');
        }
    }

    // iter for word in words
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if (arr[i] & arr[j]) {
                // two words share common letters
            }
            else {
                product = strlen(words[i]) * strlen(words[j]);
                if (product > max) {
                    max = product;
                }
            }
        }
    }

    return max;
}
