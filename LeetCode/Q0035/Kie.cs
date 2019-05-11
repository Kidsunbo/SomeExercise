using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kie
{
    public class Solution
    {
        public int SearchInsert(int[] nums, int target)
        {
            var beg = 0;
            var end = nums.Length - 1;
            while(beg<end)
            {
                var mid = (end + beg) / 2;
                if (nums[mid] < target) beg = mid + 1;
                else if (nums[mid] > target) end = mid - 1;
                else return mid;
            }
            if (nums[beg] < target) return ++beg;
            else return beg;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            var s = new Solution();
            Console.WriteLine(s.SearchInsert(new int[] { 1,2,3,4,5,7,8 },9));
            Console.Read();
        }
    }
}
