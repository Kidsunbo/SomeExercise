using System;

namespace Kie
{
    class Kie
    {
        static void Main(string[] args)
        {
            var s = new Solution();
            var nums1 = new int[]{ 1, 2, 3, 0, 0, 0 };
            var nums2 = new int[] { 2, 5, 6 };
            s.Merge(nums1, 3, nums2, 3);
            Console.WriteLine(string.Join(',',nums1));
        }
    }

    public class Solution
    {
        public void Merge(int[] nums1, int m, int[] nums2, int n)
        {
            var lastIndex = m + n;
            while(m>0 && n > 0)
            {
                if (nums1[m-1] > nums2[n-1])
                {
                    nums1[lastIndex-- - 1] = nums1[m-- - 1];
                }
                else
                {
                    nums1[lastIndex-- - 1] = nums2[n-- - 1];
                }
            }
            if(n > 0)
            {
                while(lastIndex > 0)
                {
                    nums1[lastIndex-- - 1] = nums2[n-- - 1];
                }
            }
        }
    }
}
