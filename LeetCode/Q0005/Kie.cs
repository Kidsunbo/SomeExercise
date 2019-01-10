using System;

namespace Program
{
    public class Solution
    {
        public string LongestPalindrome(string s)
        {
            bool flag = false;
            for (int l = s.Length; l > 0; l--)
            {
                for (int i = 0; i < s.Length - l + 1; i++)
                {
                    for (int j = l + i - 1, k = i; j >= k; j--, k++)
                    {
                        if (s[j] != s[k])
                        {
                            flag = false;
                            break;
                        }
                        flag = true;
                    }
                    if (flag)
                    {
                        return s.Substring(i, l);
                    }

                }

            }
            return "";
        }

        static void Main(string[] args)
        {
            var s = new Solution();
            Console.WriteLine(s.LongestPalindrome("hellolleh"));
        }
    }
}
