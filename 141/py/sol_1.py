"""leetcode 141. Linked List Cycle I

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
    def hasCycle(self, head: ListNode) -> bool:
        if head == None:
            return False

        nset = set()
        node = head

        while True:
            if node in nset:
                return True
            else:
                nset.add(node)

            if node.next is None:
                return False
            else:
                node = node.next
