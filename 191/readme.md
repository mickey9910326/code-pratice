# 191. Number of 1 Bits

    Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

    Note:

    Note that in some languages such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
    In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3 above, the input represents the signed integer. -3.

    Follow up: If this function is called many times, how would you optimize it?

## Method 1

這題在大學時已經看過算法，所以馬上就想到使用這個方式來實現。這邊嘗試以文字及圖表來講解此方法。

### 構思

將數字以二進位01的方式呈現，可以將`1`表示為"有一個bit 1出現"，`0`表示為"有零個bit 1出現"，
所以將0跟1全部加起來就可以得到該數字中有幾個bit 1。
以資料的角度來看，可以當作每一位元的資料儲存了有幾個bit 1出現。

拿217這個數字來舉例。`217 = 0xD9 = 0b1101 1001`。
將217中的所有‵`0`與`1`加起來，`1+1+0+1+1+0+0+1=5`。
即可得出有5個bit 1出現。

所以我們只需要找到一個高效率的方式來將所有`0`與`1`相加，即可得到有幾個bit 1。

這個演算法的概念如下：

- 每一位元的資料儲存了有幾個bit 1出現，把一位原資料與一位原資料相加，得到兩位元的資料。
- 每二位元的資料儲存了有幾個bit 1出現，把二位原資料與二位原資料相加，得到四位元的資料。
- 每四位元的資料儲存了有幾個bit 1出現，把四位原資料與四位原資料相加，得到八位元的資料。
- 每八位元的資料儲存了有幾個bit 1出現，把八位原資料與八位原資料相加，得到十六位元的資料。
- 每十六位元的資料儲存了有幾個bit 1出現，把十六位原資料與十六位原資料相加，得到三二位元的資料
，即此數字中有幾個bit 1出現。

### 實現

```c
#define U32_M1 (uint32_t)(0x55555555)
#define U32_M2 (uint32_t)(0x33333333)
#define U32_M4 (uint32_t)(0x0F0F0F0F)
#define U32_M8 (uint32_t)(0x00FF00FF)
#define U32_M16 (uint32_t)(0x0000FFFF)

int hammingWeight(uint32_t n) {
    n = (n & U32_M1) + ((n >> 1) & U32_M1);
    n = (n & U32_M2) + ((n >> 2) & U32_M2);
    n = (n & U32_M4) + ((n >> 4) & U32_M4);
    n = (n & U32_M8) + ((n >> 8) & U32_M8);
    n = (n & U32_M16) + ((n >> 16) & U32_M16);

    return n;
}
```

### 例子

這邊以 0xAAAAF731 這數字做為例子來解說。
二進位為 `0b 10101010 10101010 111110111 00110001`，共有18個bit 1。

`U32_M1 = 0x55555555 = 0b 01010101 01010101 01010101 01010101`

所以`n = (n & U32_M1) + ((n >> 1) & U32_M1);`
的作用為將相鄰兩個一位元的資料相加，如此可得這兩個一位元中有幾個bit 1出現，
並把這個資料放回這兩位元中。

- `(n & U32_M1)`

  可以取得位元位置0,2,4,6,8,16...30存放的一位原資料。

- `((n >> 1) & U32_M1)`

  可以取得位元位置1,3,5,7,9,17...31存放的一位原資料。

以表格來表示的化如下：

| n中的資料  | 0,1 | 0,1 | 0,1 | 0,1 | 0,1 | 0,1 | 0,1 | 0,1 | 1,1 | 1,1 | 0,1 | 1,1 | 0,0 | 1,1 | 0,0 | 0,1 |
| ---------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
|            | 0+1 | 0+1 | 0+1 | 0+1 | 0+1 | 0+1 | 0+1 | 0+1 | 1+1 | 1+1 | 0+1 | 1+1 | 0+0 | 1+1 | 0+0 | 0+1 |
| num of '1' | 1   | 1   | 1   | 1   | 1   | 1   | 1   | 1   | 2   | 2   | 1   | 2   | 0   | 2   | 0   | 1   |
| encoded    | 01  | 01  | 01  | 01  | 01  | 01  | 01  | 01  | 10  | 10  | 01  | 10  | 00  | 10  | 00  | 01  |

運算後可得`0b 01010101 01010101 10100110 00100001`

這時候要以每二位元來觀察n這個數字，`01`表示有1個bit 1出現，`10`表示有2個bit 1出現。

接著`n = (n & U32_M2) + ((n >> 2) & U32_M2);`
把相鄰兩個二位元的資料相加，如此可得這兩個二位元中有幾個bit 1出現，
並把這個資料放回這四位元中。

- `(n & U32_M2)`

  可以取得位元位置0,4, 8,12,16,20,24,28存放的二位原資料。

- `((n >> 2) & U32_M2)`

  可以取得位元位置2,6,10,14,18,22,26,30存放的二位原資料。

| n中的資料  | 01,01 | 01,01 | 01,01 | 01,01 | 10,10 | 01,10 | 00,10 | 00,01 |
| ---------- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
|            | 1 + 1 | 1 + 1 | 1 + 1 | 1 + 1 | 2 + 2 | 1 + 2 | 0 + 2 | 0 + 1 |
| num of '1' | 2     | 2     | 2     | 2     | 4     | 3     | 2     | 1     |
| encoded    | 0010  | 0010  | 0010  | 0010  | 0100  | 0011  | 0010  | 0001  |

運算後可得`0b 00100010 00100010 01000011 00100001`

這時候要以每二位元來觀察n這個數字，`01`表示有1個bit 1出現，`10`表示有2個bit 1出現。

接著`n = (n & U32_M4) + ((n >> 4) & U32_M4);`
把相鄰兩個四位元的資料相加，如此可得這兩個四位元中有幾個bit 1出現，
並把這個資料放回這八位元中。

- `(n & U32_M4)`

  可以取得位元位置0, 8,16,24存放的四位原資料。

- `((n >> 4) & U32_M4)`

  可以取得位元位置4,12,20,28存放的四位原資料。

| n中的資料  | 0010,0010 | 0010,0010 | 0100,0011 | 0010,0001 |
| ---------- | --------- | --------- | --------- | --------- |
|            | 2 + 2     | 2 + 2     | 4 + 3     | 2 + 1     |
| num of '1' | 4         | 4         | 7         | 3         |
| encoded    | 00000100  | 00000100  | 00000007  | 00000003  |

以此類推，做相鄰八位元資料相加。

| n中的資料  | 00000100,00000100 | 00000007,00000003 |
| ---------- | ----------------- | ----------------- |
|            | 4 + 4             | 7 + 3             |
| num of '1' | 8                 | 10                |
| encoded    | 00000000,00001000 | 0000000,00001010  |

以此類推，做相鄰十六位元資料相加，得到一個三十二位元的資料，即為總共有幾個bit 1出現。

| n中的資料  | 0000000000001000,000000000001010   |
| ---------- | ---------------------------------- |
|            | 8 + 10                             |
| num of '1' | 18                                 |
| encoded    | 00000000,00000000,0000000,00010010 |

### 總結

此方法除非是天才，不然應該很難憑空想像出來，但是演算法的思路可以好好的品味。速度方面大約是比遍歷每個bit檢查快32倍。

若不懂上面的描述方法，可參考維基百科。

- 時間複雜度：O(1)
- 空間複雜度：O(1)

## Method 2 遍歷每個bit檢查

### 構思

此方法非常直覺，使用迴圈去遍歷每個bit，檢查其是否為1，並累加到計數器即可。

### 實現

```c
int hammingWeight(uint32_t n) {
    int count = 0;

    while (n != 0) {
        if (n & 1) {
            count++;
        }

        n = n >> 1;
    }

    return count;
}
```

### 總結

- 時間複雜度：O(1)
- 空間複雜度：O(1)

## Method 3

這方法看 leetcoe 的 solution 才想起有這個位元操作方法。

### 構思

使用`n&(n-1)`運算將最後一個位子的bit 1翻轉為0，運算數次後`n`中所有的bit 1都會被翻轉為0，使用迴圈計算次數即可知道`n`中有幾個bit 1出現。

下圖很好的解釋了`n&(n-1)`運算的作用原理，如果不清楚可以到[leetcode](https://leetcode.com/problems/number-of-1-bits/solution/)觀看文字說明。

![191_Number_Of_Bits](https://leetcode.com/media/original_images/191_Number_Of_Bits.png)

上圖取自leetcode。

### 實現

```c
int hammingWeight(uint32_t n) {
    int sum = 0;
    while (n != 0) {
        sum++;
        n &= (n - 1);
    }
    return sum;
}
```

### 總結

此方法利用了`n&(n-1)`運算，只遍歷了為1的位元。

`n&(n-1)`運算最後一個位子的bit 1翻轉為0。

- 時間複雜度：O(1)
- 空間複雜度：O(1)

## 動態語言

在動態語言中，如果要計算位元數，應使用內建的函式來提升效率。

以 python 來說，應使用 `bin(n).count("1")` 來計算bit 1出現的次數，
雖難其作用方式為將其轉為'0'與'1'組成之字串，並計算'1'出現的次數。
但其使用c實現，`count`複雜度為`O(n)`，若使用python來實現上面的演算法，運算量跟記憶體會多出非常多。

詳見 [cpyhton 3.6 listcount implement](https://github.com/python/cpython/blob/3.6/Objects/listobject.c#L2177-L2191)

在 3.10 之後的 python 新增了 `bit_count` 函式，可以直接計算有幾個bit 1在數字中。

python 3.10 內部實現也是使用上述的方法一，詳見下方連結。

[cpyhton 3.10 _Py_popcount32 implement](https://github.com/python/cpython/blob/b3b98082c5431e77c64cab2c85525a804436b505/Include/internal/pycore_bitutils.h#L94-L130)

## GCC & CLANG

因為此運算滿常使用在一些地方，所以現在很多CPU架構都有指令來支援此運算。
詳見 [英文維基 - SSE4](https://en.wikipedia.org/wiki/SSE4#POPCNT_and_LZCNT)。

在 gcc 中可以使用 `__builtin__popcount`， clang 中可以使用 `_mm_popcnt_u32` 或 `_mm_popcnt_u64`。

## Reference

1. [中文維基 - 漢明重量](https://zh.wikipedia.org/wiki/汉明重量)
2. [英文維基 - Hamming weight](https://en.wikipedia.org/wiki/Hamming_weight)
3. [面试官：计算一下二进制中1的数量？](https://zhuanlan.zhihu.com/p/146025115)
4. [cpyhton 3.10 _Py_popcount32 implement](https://github.com/python/cpython/blob/b3b98082c5431e77c64cab2c85525a804436b505/Include/internal/pycore_bitutils.h#L94-L130)
5. [英文維基 - SSE4](https://en.wikipedia.org/wiki/SSE4#POPCNT_and_LZCNT)
6. [gcc onlinedocs - 6.59 Other Built-in Functions Provided by GCC](https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html)
7. [clang doxygen - popcntintrin.h File Reference](https://clang.llvm.org/doxygen/popcntintrin_8h.html)
