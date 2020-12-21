/**
 * @file sol_3.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief 191. Number of 1 Bits
 * @date 2020.12.21
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

#include <inttypes.h>

/**
 * @brief The number of '1' bits in n.
 *
 * @param n Unsigned integer.
 * @return int The number of '1' bits.
 */
int hammingWeight(uint32_t n) {
    int sum = 0;
    while (n != 0) {
        sum++;
        n &= (n - 1);
    }
    return sum;
}
