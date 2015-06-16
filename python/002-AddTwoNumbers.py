# Definition for singly-linked list.
class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def addTwoNumbers(self, l1, l2):
        head, carry, x, y = ListNode(0), 0, 0, 0
        currNode = head        
        while l1 or l2 :
            if l1 :
                x, l1 = l1.val, l1.next
            else :
                x = 0
            if l2 :
                y, l2 = l2.val, l2.next
            else : 
                y = 0 
            s = x + y + carry
            carry = int(s / 10)
            s = s % 10
            currNode.next = ListNode(s)
            currNode = currNode.next
        if carry > 0 :
            currNode.next = ListNode(carry)
        return head.next

l1 = ListNode(3)
l2 = ListNode(9)
solution = Solution()
l = solution.addTwoNumbers(l1, l2)
while l :
    print(l.val)
    l = l.next