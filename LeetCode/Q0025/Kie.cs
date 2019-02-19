using System;

namespace Temp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Solution s = new Solution();
            s.print(3, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0);
        }
    }

    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }


    }

    public static class Extention
    {
        private static ListNode create(this Solution s, params int[] args)
        {
            ListNode head = new ListNode(0);
            var result = head;
            foreach (var i in args)
            {
                head.next = new ListNode(i);
                head = head.next;
            }
            return result.next;
        }

        public static void print(this Solution s, int k,params int[] args)
        {
            var l = s.ReverseKGroup(s.create(args),k);
            while (l != null)
            {
                Console.Write(l.val);
                l = l.next;
            }
        }
    }

    public class Solution
    {
        public ListNode ReverseKGroup(ListNode head, int k)
        {
            if (head is null) return null;
            var container = new ListNode[k];
            var temp = head;
            for(var i = 0; i < k; i++)
            {
                if (temp == null) return head;
                container[i] = temp;
                temp = temp.next;
            }
            for(var i = k - 1; i > 0; i--)
            {
                container[i].next = container[i - 1];
            }
            container[0].next = ReverseKGroup(temp, k);
            return container[k - 1];
        }
    }
}
