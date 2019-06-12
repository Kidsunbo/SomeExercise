using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleApplication1
{

    public class Solution
    {
       
        public IList<IList<int>> CombinationSum2(int[] candidates, int target)
        {

            Array.Sort(candidates);


            return findResult(candidates, 0,target);
        }

        public IList<IList<int>> findResult(int[] candidates, int start, int target)
        {
            var result = new List<IList<int>>();
            for(var i = start; i < candidates.Length; i++)
            {
                if (i > start && candidates[i] == candidates[i-1]) continue;
                if (candidates[i] == target)
                {
                    result.Add(new List<int>() { candidates[i] });
                    return result;
                }
                else if (candidates[i] > target) break;
                else if (candidates[i] < target)
                {
                    var r = findResult(candidates, i + 1, target - candidates[i]);
                    foreach(var item in r)
                    {
                        item.Insert(0, candidates[i]);
                        result.Add(item);
                    }
                }
            }
            return result;
        }
    }
    class Kie
    {
        static void Main(string[] args)
        {
            var s = new Solution();
            var r = from i in s.CombinationSum2(new int[] { 8,8,8,8,8,8,8,1,7,1,7,2,6,2,6 }, 8)
            select string.Join(",", i);
            Console.WriteLine(string.Join("\n", r));

            Console.Read();
        }
    }
}
