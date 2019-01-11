using System;

namespace temp
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = new Solution();
            Console.WriteLine(s.IsMatch("",""));
            Console.WriteLine(s.IsMatch("", ".*"));
            Console.WriteLine(s.IsMatch("", "."));
            Console.WriteLine(s.IsMatch("abc", "."));
            Console.WriteLine(s.IsMatch("", "a*"));
            Console.WriteLine(s.IsMatch("abc", "abc"));
            Console.WriteLine(s.IsMatch("abc", "a.c"));
            Console.WriteLine(s.IsMatch("abbbc", "a.*c"));
            Console.WriteLine(s.IsMatch("ac", "a.*c"));
            Console.WriteLine(s.IsMatch("abc", "abcc*c*.*a*"));
            Console.WriteLine(s.IsMatch("abc", ".*"));
            Console.WriteLine(s.IsMatch("ab", ".*c"));
            Console.WriteLine(s.IsMatch("aaa", "a*a"));



        }
    }
    public class Solution
    {
        public bool IsMatch(string s, string p)
        {
            if (p.Length == 0) return s.Length == 0;
            bool match = s.Length != 0 && (s[0] == p[0] || p[0] == '.');
            if (p.Length > 1 && p[1] == '*') return match && IsMatch(s.Substring(1), p) || IsMatch(s, p.Substring(2));
            else return match && IsMatch(s.Substring(1), p.Substring(1));
        }


    }
}
