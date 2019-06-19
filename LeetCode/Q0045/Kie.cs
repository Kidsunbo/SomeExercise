using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kie
{
    public class Solution
    {
        public int Jump(int[] nums)
        {
            if (nums.Length == 0) return 0;
            int current = 0;
            int steps = 0;
            while (current < nums.Length-1)
            {
                steps++;
                var max = 0;
                var index = 0;
                if (nums[current] >= nums.Length-1 - current) return steps;
                for(var i = 1; i <= nums[current]; i++) {
                    var temp = i + nums[current + i];
                    if (max < temp)
                    {
                        max = temp;
                        index = current+i;
                    }
                }
                current = index;
                if (current >= nums.Length - 1) return steps;
            }
            return steps;
        }
    }

    class Kie
    {
        static void Main(string[] args)
        {
            var s = new Solution();
            Console.WriteLine(s.Jump(new int[] { 2,3,1 }));
            Console.Read();
        }
    }
}
