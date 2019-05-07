using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace Test
{
    public class Solution
    {
        public IList<int> FindSubstring(string s, string[] words)
        {
            if (string.IsNullOrEmpty(s) || words.Length == 0) return new List<int>();
            Dictionary<string, int> dic = new Dictionary<string, int>();
            foreach (var i in words) dic[i]=dic.GetValueOrDefault(i)+1;
            var result = new List<int>();
            for(int i = 0; i <= s.Length - words[0].Length * words.Length; i++)
            {
                var d = new Dictionary<string, int>();
                var j = i;
                var n = words[0].Length;
                var count = 0;
                while (count < words.Length)
                {
                    var sub = s.Substring(j, n);
                    d[sub]=d.GetValueOrDefault(sub)+1;
                    if (d[sub] > dic.GetValueOrDefault(sub)) break;
                    count++;
                    j += n;
                }
                if (count == words.Length) result.Add(i);
            }
            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var s = new Solution();
            Console.WriteLine(string.Join(",", s.FindSubstring("xqlscumol",
             new string[] { "ql","sc"})));
        }
    }
}
