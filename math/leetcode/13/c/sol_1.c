/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief leetcode 1019. Next Greater Node In Linked List
 * @date 2021.05.07
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

int romanToInt(char* s) {
    const static map[256] = {
        ['I'] = 1,   ['V'] = 5,   ['X'] = 10,   ['L'] = 50,
        ['C'] = 100, ['D'] = 500, ['M'] = 1000,
    };

    int sum = 0;
    int curr;
    int prev = 0;

    while (*s != '\0') {
        curr = map[*s];

        if (prev < curr) {
            sum -= prev;
        }
        else {
            sum += prev;
        }
        prev = curr;
        s++;
    }
    sum += curr;

    return sum;
}
