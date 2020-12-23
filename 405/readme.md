# 405. Convert a Number to Hexadecimal

    Given an integer, write an algorithm to convert it to hexadecimal. For
    negative integer, two’s complement method is used.

    Note:

        1. All letters in hexadecimal (a-f) must be in lowercase.

        2. The hexadecimal string must not contain extra leading 0s. If the
           number is zero, it is represented by a single zero character '0';
           otherwise, the first character in the hexadecimal string will not
           be the zero character.

        3. The given number is guaranteed to fit within the range of a 32-bit
           signed integer.

        4. You must not use any method provided by the library which
           converts/formats the number to hex directly.

## Method 1

### 思路

1. 讀取32bit整數中每4bit轉換成對應的hex number(0~9,a~f)。
2. 題目要求字串開頭不需要補零，所以先計算num的大小，得出hex string的長度。
3. hex string 會把數字低位元部分放至尾巴。迴圈方向選擇從數字低位元往高位元
   ，字串從尾巴往頭前進。
4. 題目要求要為二補數形式，而gcc int存放數值的方式，即為二補數，故不需要多做其他操作。

### 過程

1. 計算num的大小，得出hex string的長度。

   這邊使用rshift來不斷右移數值，並累加長度變數`len`，
   若數值變為0，則代表後續已經沒有有效的資料可以使用了，
   此時`len`便會是hex string的長度。

   因為gcc對rshift的操作方式如下，
   - 如果是正數，右移並補零。
   - 如果是負數，右移並補一。

   所以這邊將`num`強制轉型成`(unsigned int)`，並存放到`num2`中，再對`num2`進行迴圈位移操作。
   在gcc中`unsigned int`的型態放入負數`int`，並不會檢查其最高位元的複數符號，
   直接將其存放到記憶體中。

   例如：`-1 (int) -> 0xFFFF FFFF FFFF FFFF -> 4294967295 (unsigned int)`

   ```c
      int len = 0;
      unsigned int num2 = num;

      while (num2 != 0) {
         len++;
         num2 >>= 4;
      }
   ```

2. 計算每個4bit對應的ascii，並存放至回傳字串中。

   一樣不斷左移數值直到數值變零，每次將最後4bit數值取出，放置`v`。
   - 如果`v`大於10因
     對應之ascii碼為`'a' + v % 10`，因為a~f的ascii碼是連續的
     ，所以可以直接加上位移，得到對應的ascii碼。
   - 如果`v`小於10
     以此類推，對應之ascii碼為`'0' + v`。

   ```c
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
   ```

3. 提交的時候發現了有個例外，`0`

   當`num`等於`0`時要回傳`'0'`，將此例外邏輯寫至開頭。

   ```c
      if (num == 0) {
         char* s = malloc(sizeof(char) * 2);
         s[0] = '0';
         s[1] = '\0';
         return s;
      }
   ```

### 實現

```c
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
```

## Method 2

### 思路

在看完討論區後，想起可以用hash去儲存每個4bit值對應的ascii碼。
占用的大小也才16bytes，滿划算的。

另外順便優化method的coding style，把變數宣告放至函式開頭。

NOTE: 有些只支援C89規範的編譯器，只能將變數宣告放置scope的開頭。

整理後，code好看了不少。

### 實現

```c
char* toHex(int num) {
    unsigned int num2;  ///< To store num as unsigned int.

    char* s;      ///< Retrun hex string.
    int len = 0;  ///< Length of hex string's'.
    int idx;      ///< Index of hex string 's' to put ascii value in.

    const int hex_ascii[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
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

```

## 後記

在看討論區的時候發現許多解答會直接`return "0"`，作為0的例外處理。

但這樣做會回傳`.data Section`中對應的位置，如果呼叫者希望繼續操作toHex回傳的`char *`，
則會操作到存放靜態資料唯獨的記憶體，造成錯誤。當然如果只有讀取是不會發生錯誤的，但是我們
不能這樣期望使用者。

可以嘗試運行下方範例看看。

```c
#include <stdio.h>
#include <stdlib.h>

char* func() {
    return "0";
}

int main(int argc, char const* argv[]) {
    char* s = func();
    printf("s = %s\n", s);
    s[0] = '1';

    return 0;
}
```
