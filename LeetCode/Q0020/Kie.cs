using System;
using System.Collections.Generic;
namespace Kie
{
    public class Solution
    {
        public bool IsValid(string s)
        {
            Stack<char> stack = new Stack<char>();
            foreach(var i in s)
            {
                if ("([{".Contains(i)) stack.Push(i);
                else
                {
                    if (stack.Count == 0) return false;
                    switch (i)
                    {
                        case ')':
                            if (stack.Pop() != '(') return false;
                            break;
                        case ']':
                            if (stack.Pop() != '[') return false;
                            break;
                        case '}':
                            if (stack.Pop() != '{') return false;
                            break;
                    }
                }
            }
            return stack.Count==0;
        }

        static void Main(string[] args)
        {
            var s = new Solution();
            Console.WriteLine(s.IsValid(""));
        }
    }
}
