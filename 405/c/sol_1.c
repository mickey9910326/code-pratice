/**
 * @file sol_1.c
 * @author LiYu87 (mickey9910326@gmail.com)
 * @brief 405. Convert a Number to Hexadecimal
 * @date 2020.12.21
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */


/**
 * @brief Change integer to hex string.
 *
 * @param num 32bit integer.
 * @return char* Hex string.
 */
char* toHex(int num) {
    if (num == 0) {
        char* s = malloc(sizeof(char) * 2);
        s[0] = '0';
        s[1] = '\0';
        return s;
    }

    int len = 0;
    unsigned int num2 = num;

    while (num2 != 0) {
        len++;
        num2 >>= 4;
    }

    char* s = malloc(sizeof(char) * (len + 1));
    int idx = len - 1;
    int v;

    s[len] = '\0';
    num2 = (unsigned int)num;

    while (num2 != 0) {
        v = num2 & 0b1111;
        if (v >= 10) {
            s[idx] = 'a' + v % 10;
        }
        else {
            s[idx] = '0' + v;
        }

        num2 >>= 4;
        idx--;
    }

    return s;
}
