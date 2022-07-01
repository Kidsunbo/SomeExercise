using System;
using System.IO;
using System.Threading.Tasks;

namespace Project
{


    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }
    }

    public class Solution
    {
        public ListNode DeleteDuplicates(ListNode head)
        {
            var before_head = new ListNode { next = head };
            ListNode op = before_head;

            while(op != null)
            {
                var (node, is_single) = SkipDuplicatesToNext(op.next);
                if (is_single)
                {
                    op = op.next;
                }
                else
                {
                    op.next = node;
                }

            }

            return before_head.next;
        }

        /// <summary>
        /// To skip the duplicates
        /// </summary>
        /// <param name="head">head is the node which must be single.</param>
        /// <returns>The next node which might be single or might not. And a boolean to indicate that if head is single</returns>
        public (ListNode, bool) SkipDuplicatesToNext(ListNode head)
        {
            if(head == null || head.next == null) {
                return (null, true);
            }

            var current_val = head.val;
            var is_single = true;
            head = head.next;
            while(head != null && head.val == current_val)
            {
                is_single = false;
                head = head.next;
            }
            return (head, is_single);
        }
    }


    class Program
    {

        static ListNode CreateList(params int[] args)
        {
            if (args.Length == 0)
            {
                return null;
            }

            var head = new ListNode(args[0]);
            var op = head;
            foreach (var i in args[1..])
            {
                op.next = new ListNode(i);
                op = op.next;
            }
            return head;
        }

        static async Task<string> PrintList(ListNode head)
        {
            if (head is null)
            {
                return "<null>";
            }

            StringWriter sw = new StringWriter();
            await sw.WriteAsync(Convert.ToString(head.val));
            head = head.next;
            while (head != null)
            {
                await sw.WriteAsync("->");
                await sw.WriteAsync(Convert.ToString(head.val));
                head = head.next;
            }
            return sw.ToString();
        }


        static async Task Main(string[] args)
        {
            var s = new Solution();
            var h = CreateList(1, 2, 3, 3, 3, 5, 5, 5, 8);
            Console.WriteLine(await PrintList(h));
            var result = s.DeleteDuplicates(h);
            Console.WriteLine(await PrintList(result));

            h = CreateList();
            Console.WriteLine(await PrintList(h));
            result = s.DeleteDuplicates(h);
            Console.WriteLine(await PrintList(result));
        }
    }
}
