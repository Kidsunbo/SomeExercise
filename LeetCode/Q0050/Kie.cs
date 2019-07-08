using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kie
{

    public class Solution
    {
        public double MyPow(double x, int n)
        {

            // //Recursive Version
            //if (n >= 0)
            //{
            //    if (n == 0) return 1;
            //    double temp = MyPow(x, n / 2);
            //    if (n % 2 == 0) return temp * temp;
            //    else return x * temp * temp;
            //}
            //else
            //{
            //    return 1 / (MyPow(x, -(n+1))*x);
            //}

            // Unrecursive version
            if (n >= 0){
                double result = 1;
                var carry = 0;
                while (true)
                {
                    carry = n % 2;
                    n /= 2;
                    if (carry == 1) result = result * x;
                    if (n == 0) return result;
                    x *= x;
                }
            }
            else
            {
                return 1 / (MyPow(x, -(n + 1)) * x);
            }
        }
    }
    class Kie
    {
        static void Main(string[] args)
        {
            var s = new Solution();
            Console.WriteLine(s.MyPow(2.00000,-2147483648));
            Console.WriteLine(s.MyPow(2,2147483647)); // This one is overflow, so the result is not correct, but it doesn't matter.
            Console.WriteLine(s.MyPow(2,11));
            Console.Read();
        }
    }
}
