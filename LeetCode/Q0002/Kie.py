# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1:ListNode, l2:ListNode):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        hand = head
        carry = 0
        while True:
            sum = l1.val+l2.val+carry
            l1 = l1.next
            l2 = l2.next
            hand.val = sum % 10
            carry = sum // 10
            if l1 is None:
                if l2 is None:
                    if carry == 1:
                        hand.next = ListNode(1)
                else:
                    hand.next = l2
                    while carry==1:
                        if l2.val ==9:
                            l2.val =0
                            if l2.next is None:
                                l2.next = ListNode(1)
                                break
                            l2 = l2.next
                        else:
                            l2.val = l2.val+carry
                            carry = 0
                return head

            if l2 is None:
                hand.next = l1
                while carry==1:
                    if l1.val ==9:
                        l1.val =0
                        if l1.next is None:
                            l1.next = ListNode(1)
                            break
                        l1 = l1.next
                    else:
                        l1.val = l1.val+carry
                        carry = 0
                return head
            hand.next = ListNode(0)
            hand = hand.next


if __name__ == '__main__':
    s = Solution()
    a = ListNode(3)
    a.next = ListNode()