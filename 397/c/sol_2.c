/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 397. Integer Replacement
 * @date 2020.12.20
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

/**
 * @brief The minimum num of operations for n to become 1.
 *
 * Operation:
 *   If n is even, replace n with n / 2.
 *   If n is odd, replace n with either n + 1 or n - 1.
 *
 * @param n Positive integer, 1 <= n <= 2e31 - 1.
 * @return int The num of operations.
 */
int integerReplacement(int n) {
    // Use last bit to ensure n is odd or even.
    // If last bit is 1, than n is odd.
    // If last bit is 0, than n is even.

    // The postion of highest bit 1 will be the times
    // that n do /2 or >>1 operation to become 1.

    // So, the num of operations will be (m + is_odd).
    // m means the postion of highest bit 1 of n.
    // is_odd means n is odd(1) or even(0).
    int times = 0;
    long long t = n;
    while (t > 1) {
        times++;
        if (t & 1) {
            if ((t & 2) && (t != 3)) {
                t++;
            }
            else {
                t--;
            }
        }
        else {
            t >>= 1;
        }
    }
    return times;
}
