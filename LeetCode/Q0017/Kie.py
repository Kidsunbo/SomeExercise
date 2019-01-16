import itertools
class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if digits=="": return []
        letters = {'1':'*','2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}

        # Cheat version. Use itertools.
        # temp = itertools.product(*[letters[i] for i in digits])
        # return list(map(lambda x:''.join(x),temp))

        # No cheat version.
        l = [*letters[digits[0]]]
        for i in digits[1:]:
            l = Solution.combineOne(letters,l,i)
        return l


    @staticmethod
    def combineOne(letters:dict,l:list,d:str):
        result = []
        for i in l:
          for c in letters[d]:
                result.append(i+c)
        return result

if __name__ == '__main__':
    s = Solution()
    print(Solution.letterCombinations(s,"234"))