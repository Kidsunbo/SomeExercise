using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kie
{

    //public class Solution
    //{
    //    // Time 10.75%  Memory 100%
    //    public string GetPermutation(int n, int k)
    //    {
    //        List<int> li = new List<int>();
    //        for(int i = 1; i <= n; i++)
    //        {
    //            li.Add(i);
    //        }
    //        for(int c = 1; c < k; c++)
    //        {
    //            var pivot = n - 2;
    //            while (pivot >= 0)
    //            {
    //                if (li[pivot+1] <= li[pivot])
    //                {
    //                    pivot--;
    //                    continue;
    //                }
    //                else break;
    //            }
    //            if (pivot == -1)
    //            {
    //                li.Reverse();
    //                continue;
    //            }
    //            int last = n - 1;
    //            while (li[last] < li[pivot])
    //            {
    //                last--;
    //            }
    //            //Swap
    //            int temp = li[last];
    //            li[last] = li[pivot];
    //            li[pivot] = temp;

    //            //Reverse
    //            li.Reverse(pivot+1, li.Count - pivot - 1);


    //        }
    //        return string.Join("",li);
    //    }
    //}

    public class Solution
    {

        private static int fact(int i)
        {
            if (i == 1||i==0) return i;
            return fact(i - 1) * i;
        }
        public string GetPermutation(int n, int k)
        {
            k -= 1;
            if (k > fact(n)) return "";
            var rest = new List<int>();
            for(int i = 1; i <= n; i++)
            {
                rest.Add(i);
            }

            var li = new List<int>();
            while (li.Count<n)
            {
                int f = fact(rest.Count-1);
                if (f == 0)
                {
                    li.Add(rest[0]);
                    break;
                }
                li.Add(rest[k / f]);
                rest.RemoveAt(k / f);
                k %= f;
            }
            return string.Join("", li);
        }
    }
    class Kie
    {
        static void Main(string[] args)
        {
            var s = new Solution();
            Console.WriteLine(s.GetPermutation(4, 9));
            Console.Read();
        }
    }
}
