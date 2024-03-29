# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if head is None:
            return None
        faster = head
        slower = head
        has_loop = False
        while faster.next is not None and faster.next.next is not None:
            slower = slower.next
            faster = faster.next.next
            if slower is faster:
                has_loop = True
                slower = head
                break
        if has_loop:
            while slower is not faster:
                slower = slower.next
                faster = faster.next
            return slower
        else:
            return None
