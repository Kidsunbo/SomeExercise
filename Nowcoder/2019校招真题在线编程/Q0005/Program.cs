using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            IEnumerable<int> input = Console.ReadLine().Split(' ').Select(int.Parse);
            int n = input.First();
            int k = input.Last();
            decimal count = 0m;
            for (int i = k+1; i <= n; i++)
            {
                int quotient = n / i;
                int reminder = i-k;
                count += quotient * reminder;
                if (k == 0) count--;// The number is between 1 and n, so if k is 0, divident can't be zero
                count += Math.Max(n % i - k + 1, 0);
            }
            Console.WriteLine(count);
            Console.Read();
        }
    }
}
