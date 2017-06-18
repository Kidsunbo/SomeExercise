# Definition for singly-linked list.
class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        first = self.toNum(l1)
        second = self.toNum(l2)
        result = first + second
        return self.toList(result)

    def toNum(self, l):
        num = 0
        i = 0
        while l:
            num += (l.val * 10 ** i)
            i += 1
            l = l.next
        return num

    def toList(self, num):
        if not num:
            return ListNode(num)
        head = temp = ListNode(0)
        while num:
            tempNum = num % 10
            num //= 10
            temp.next = ListNode(tempNum)
            temp = temp.next

        return head.next


if __name__ == "__main__":
    s = Solution()
    a = s.toList(555)
    b = s.toList(666)
    print(s.toNum(s.addTwoNumbers(a,b)))