using System;
using System.Collections.Generic;

namespace temp
{
    public class Solution
    {
        public IList<IList<int>> ThreeSum(int[] nums)
        {

            var result = new List<IList<int>>();
            if(nums.Length<3)
            {
                return result;
            }
            Array.Sort(nums);
            Console.WriteLine(string.Join(",",nums));
            for (int i = 0; i < nums.Length - 2; i++)
            {
                var j = i + 1;
                var k = nums.Length - 1;
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                while (j < k)
                {
                    if (j > i + 1 && nums[j] == nums[j - 1])
                    {
                        j++;
                        continue;
                    }
                    var s = nums[i] + nums[j] + nums[k];
                    if (s == 0)
                    {
                        result.Add(new List<int> { nums[i], nums[j], nums[k] });
                        j++;
                        k--;
                    }
                    else if (s > 0) k--;
                    else j++;
                }
            }
            return result;
        }

        static void Main(string[] args)
        {
            var s = new Solution();
            foreach(var i in s.ThreeSum(new int[] {-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0 }))
            {
                foreach(var j in i)
                {
                    Console.Write($"{j} ");
                }
                Console.WriteLine();
            }
        }

    }
}
