/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief 191. Number of 1 Bits
 * @date 2020.12.21
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

#include <inttypes.h>

#define U32_M1 (uint32_t)(0x55555555)
#define U32_M2 (uint32_t)(0x33333333)
#define U32_M4 (uint32_t)(0x0F0F0F0F)
#define U32_M8 (uint32_t)(0x00FF00FF)
#define U32_M16 (uint32_t)(0x0000FFFF)

/**
 * @brief The number of '1' bits in n.
 *
 * @param n 32bits unsigned integer.
 * @return int The number of '1' bits.
 */
int hammingWeight(uint32_t n) {
    n = (n & U32_M1) + ((n >> 1) & U32_M1);
    n = (n & U32_M2) + ((n >> 2) & U32_M2);
    n = (n & U32_M4) + ((n >> 4) & U32_M4);
    n = (n & U32_M8) + ((n >> 8) & U32_M8);
    n = (n & U32_M16) + ((n >> 16) & U32_M16);

    return n;
}
