using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kie
{

    public class Solution
    {
        public static bool IsBase(string s)
        {
            if (s.Length == 0) return false;  //In case when the input is only 'e'
            bool metdot = false;
            bool metnum = false;
            if (s[0] == '+' || s[0] == '-') //When the first charactor is sign
            {
                for (var i=1;i<s.Length;i++)
                {
                    if (s[i] == '.') 
                    {
                        if (!metdot) metdot = true; // Dot can only be seen once
                        else return false;
                    }
                    else if (s[i] >= '0' && s[i] <= '9') metnum = true; // Record if number has been met
                    else return false;
                }
            }
            else
            {
                foreach(var c in s)
                {
                    if (c == '.')
                    {
                        if (!metdot) metdot = true;
                        else return false;
                    }
                    else if (c >= '0' && c <= '9') metnum = true;
                    else return false;
                }
            }
            return metnum;
        }

        public static bool IsExp(string s)
        {
            if (s.Length == 0) return false;
            bool metnum = false;
            if (s[0] == '+' || s[0] == '-')
            {
                for(int i = 1; i < s.Length; i++)
                {
                    if (s[i] < '0' || s[i] > '9') return false;
                    else metnum = true;
                }
            }
            else
            {
                foreach(var c in s)
                {
                    if (c < '0' || c > '9') return false;
                    else metnum = true;
                }
            }
            return metnum;
        }

        public bool IsNumber(string s)
        {
            s=s.Trim();
            if (s.Length == 0) return false;
            var ss = s.Split('e');
            if (ss.Length == 1)
            {
                return IsBase(ss[0]);
            }
            else if (ss.Length == 2)
            {
                return IsBase(ss[0]) && IsExp(ss[1]);
            }
            else
            {
                return false;
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var s = new Solution();
            while (true)
            {
                string data = Console.ReadLine();
                Console.WriteLine(s.IsNumber(data));
            }
        }
    }
}
