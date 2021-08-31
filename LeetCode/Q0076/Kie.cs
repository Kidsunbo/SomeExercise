using System;
using System.Collections.Generic;
using System.Linq;

namespace Kie
{
    public class Solution
    {


        public string MinWindow(string s, string t)
        {
            if(s.Length==0 || t.Length == 0)
            {
                return "";
            }

            var countMap = new Dictionary<char, int>();
            foreach (var c in t)
            {
                countMap[c] = countMap.GetValueOrDefault(c, 0) + 1;
            }

            int r = 0;
            int l = 0;
            int matched = 0;

            int minLength = -1;
            int minL = 0;

            while (r < s.Length)
            {
                if (countMap.ContainsKey(s[r])){
                    countMap[s[r]]--;
                    if(countMap[s[r]]==0)
                    {
                        matched++;
                    }
                }

                while(l<=r && matched == countMap.Count)
                {
                    if(minLength==-1 || r - l + 1 < minLength)
                    {
                        minLength = r - l + 1;
                        minL = l;
                    }
                    if (countMap.ContainsKey(s[l]))
                    {
                        countMap[s[l]]++;
                        if(countMap[s[l]] > 0)
                        {
                            matched--;
                        }
                    }
                    l++;
                }
                r++;
            }

            if(minLength == -1)
            {
                return "";
            }
            return s.Substring(minL,minLength);
        }


        static void Main(string[] args)
        {
            var s = new Solution();
            Console.WriteLine(s.MinWindow("cabefgecdaecf","cae"));
        }

    }
}
