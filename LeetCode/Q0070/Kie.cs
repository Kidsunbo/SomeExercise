using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kie
{
    /*
    // Time 72.35%  Memory 5.88%
    // Just Remember all the result which has been calculated
    public class Solution
    {
        public int ClimbStairs(int n)
        {

            return goNext(0, n, new int[n]);
        }

        private static int goNext(int cur, int total, int[] memo)
        {
            if (cur > total) return 0;
            if (cur == total) return 1;
            if (memo[cur] != 0) return memo[cur];
            memo[cur] = goNext(cur + 1, total, memo) + goNext(cur + 2, total, memo);
            return memo[cur];
        }
    }
    */

    /*
    // Time 72.35%  Memory 5.88%
    // Dynamic programming
    public class Solution
    {
        public int ClimbStairs(int n)
        {
            if (n == 1) return 1;
            var arr = new int[n];
            arr[0] = 1; // To the first step
            arr[1] = 2; // To the second step
            for (var i = 2; i < n; i++)
            {
                arr[i] = arr[i - 1] + arr[i - 2];
            }
            return arr[n - 1];
        }
    }
    */


    // Time 100%   Memory 5.88%
    public class Solution
    {
        public int ClimbStairs(int n)
        {
            if (n == 0) return 0;
            if (n == 1) return 1;
            int a = 1;
            int b = 2;
            int temp;
            for (; n > 2; n--)
            {
                temp = a + b;
                a = b;
                b = temp;
            }
            return b;
        }
    }




    class Program
    {
        static void Main(string[] args)
        {
            var s = new Solution();
            for (int i = 0; i < 100; i++)
            {
                Console.WriteLine(s.ClimbStairs(i));
            }
            Console.ReadLine();
        }
    }
}
