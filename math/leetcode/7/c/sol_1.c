/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 7. Reverse Integer
 * @date 2020.12.23
 *
 * Time Complexity: O(n) based on digit of number 'x'
 * Space Complexity: O(1)
 *
 * NOTE: By the require of question,
 *       should not use type size bigger than 32 bits (e.g. long int).
 */

#include <stdint.h>

/**
 * @brief Reverse digits of an integer.
 *
 *  123 ->  321
 * -123 -> -321
 *
 * @param x 32bit signed integer.
 * @return int Reversed integer.
 */
int reverse(int x) {
    int ret = 0;
    int remainder;

    while (x != 0) {
        remainder = x % 10;

        if (ret > INT32_MAX / 10) {
            return 0;
        }
        else if (ret < INT32_MIN / 10) {
            return 0;
        }
        else if (ret == (INT32_MAX / 10) && remainder > INT32_MAX % 10) {
            return 0;
        }
        else if (ret == (INT32_MIN / 10) && remainder < INT32_MIN % 10) {
            return 0;
        }

        ret = ret * 10 + remainder;

        x /= 10;
    }

    return ret;
}
