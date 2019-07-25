using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kie
{
    class Kie
    {
        static void Main(string[] args)
        {
            var s = new Solution();
            Console.WriteLine(s.CanJump(new int[] { 3, 2, 1, 0, 4 }));
            Console.Read();
        }
    }

    public class Solution
    {
        public bool CanJump(int[] nums)
        {
            if (nums.Length == 0) return true;
            var cur_ind = 0;
            while (true)
            {
                if (nums[cur_ind] + cur_ind >= nums.Length - 1) return true;
                var max_ind = 0;
                for (int i = 1; i <= nums[cur_ind]; i++)
                {
                    if (i + nums[cur_ind + i] >= max_ind + nums[cur_ind + max_ind]) max_ind = i;
                }
                cur_ind = cur_ind + max_ind;
                if (nums[cur_ind] == 0) return false;
            }

        }
    }
}
