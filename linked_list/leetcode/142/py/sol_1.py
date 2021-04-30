"""leetcode 142. Linked List Cycle II

Using sets to slove.

Time Complexity: O(n)
Space Complexity: O(n)
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if head == None:
            return None

        nset = set()
        node = head

        while True:
            if node in nset:
                return node
            else:
                nset.add(node)

            if node.next is None:
                return None
            else:
                node = node.next
