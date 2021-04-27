# Linked List

## Sentinel node 前哨節點

在資料結構中加入一個暫時用的節點，拿來做為邊界的節點。可讓程式不考慮邊界條件，少寫許多判斷式。

wiki中有些許的介紹及應用場景可以看。

### 參考

- [wiki - Sentinel node](https://en.wikipedia.org/wiki/Sentinel_node)

### 例子 leetcode 1171 Remove Zero Sum Consecutive Nodes from Linked List

指標`p`拿來索引list，`pre_p`則紀錄`p`的前一個node。
所以最開始`p`指向list的開頭時，`pre_p`沒辦法給予任何節點，只好選擇`null`作為值。
當整個list的總合為0時，也無法直接刪除節點，只能回傳`null`。

更改前的核心演算法中的判斷部分：

```c
    if (sum == 0) {
        // the sum of node p to pre node of q is zero
        // remove them out of list

        if (pre_p == NULL) {
            // boundary case
            // sum of head to pre node of q is zero
            head = q;
            p = q;

            if (q == NULL) {
                // boundary case
                // sum of head to end is zero
                return NULL;
            }
        }
            else {
                pre_p->next = q;
                p = q;
            }
    }
```

更改一下演算法，在`head`之前增加一個前哨節點`sentinel`指向`head`。
`pre_p`的初始值便可以設定為`sentinel`，便可以減少後續的許多邊界條件判斷。
提升程式碼的可讀性。


```c
struct ListNode sentinel = {.next = head, .val = 0};
struct ListNode* pre_p = &sentinel;
struct ListNode* p = head;
struct ListNode* q = head;
```

更改後的核心演算法：

```c
while (p != NULL) {
    sum = p->val;

    q = p->next;
    while (q != NULL && sum != 0) {
        sum += q->val;

        // NOTE: q will pointer to next node even though sum is zero
        q = q->next;
    }

    if (sum == 0) {
        // the sum of node p to pre node of q is zero
        // remove them out of list
        pre_p->next = q;
        p = q;
    }
    else {
        pre_p = p;
        p = p->next;
    }
}
```

完整的code可以參考：

- `linked_list\leetcode\1171\c\sol_1.c`
- `linked_list\leetcode\1171\c\sol_2.c`
