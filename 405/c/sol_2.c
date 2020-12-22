/**
 * @file sol_2.c
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
    unsigned int num2;  ///< To store num as unsigned int.

    char* s;      ///< Retrun hex string.
    int len = 0;  ///< Length of hex string's'.
    int idx;      ///< Index of hex string 's' to put ascii value in.

    const hex_ascii[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                           '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    // zero expetion
    if (num == 0) {
        len = 2;
        s = malloc(sizeof(char) * len);

        s[0] = '0';
        s[1] = '\0';
        return s;
    }

    // Calculate the length of hex string.
    num2 = num;
    while (num2 != 0) {
        len++;
        num2 >>= 4;
    }
    s = malloc(sizeof(char) * (len + 1));

    s[len] = '\0';

    num2 = (unsigned int)num;
    idx = len - 1;

    // Put matched ascii to hex string for each 4 bit in number.
    while (num2 != 0) {
        s[idx] = hex_ascii[num2 & 0b1111];

        num2 >>= 4;
        idx--;
    }

    return s;
}
