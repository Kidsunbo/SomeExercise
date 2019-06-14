class Solution:
    def trap(self, height) -> int:
        if len(height) == 0: return 0
        highest = max(height)
        i_highest = height.index(highest)
        sum=0
        minus = 0
        last = 0
        for i,v in enumerate(height[:i_highest+1]):
            if v>height[last]:
                sum+= height[last]*(i-last)-minus
                minus=v
                last=i
                continue
            minus+=v
        minus = 0
        last=len(height)-1
        for i,v in list(enumerate(height))[-1:i_highest:-1]:
            if v>height[last]:
                sum+=height[last]*(last-i)-minus
                minus=v
                last=i
                continue
            minus+=v
        sum += height[last] * (last - i_highest) - minus
        return sum




if __name__ == '__main__':
    s = Solution()
    print(s.trap([2,0,2]))
