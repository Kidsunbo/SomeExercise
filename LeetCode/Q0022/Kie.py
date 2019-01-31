class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        l = []
        self.generateParenthesisHelper(n,n,"",l)
        return l

    def generateParenthesisHelper(self,left,right,s,l):

        if left>right:
            return
        if left==0 and right==0:
            l.append(s)
            return
        if left>0:
            self.generateParenthesisHelper(left-1,right,s+"(",l)
        if right>0:
            self.generateParenthesisHelper(left,right-1,s+")",l)


if __name__ == '__main__':
    s = Solution()
    print(*s.generateParenthesis(13),sep='\n')
