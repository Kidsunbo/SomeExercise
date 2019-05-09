class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]
        max_num = 0
        for i,c in enumerate(s):
            if c=='(':
                stack.append(i)
            elif c==')':
                stack.pop()
                if len(stack)==0:
                    stack.append(i)
                else: max_num = max(max_num,i-stack[-1])
        return max_num


if __name__ == '__main__':
    s = Solution()
    print(s.longestValidParentheses("()()"))
