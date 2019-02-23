class Solution:
    def removeElement(self, nums: list, val: int) -> int:
        remove = 0
        for i in nums:
            if i == val:
                remove+=1

        for i in range(len(nums)-remove):
            while nums[i]==val:
                for j in range(i,len(nums)-1):
                    nums[j],nums[j+1]=nums[j+1],nums[j]

        count =0
        for i in nums:
            if i==val:
                break
            count+=1
        return count




if __name__ == '__main__':
    s = Solution()
    l = [0,1,2,2,3,0,4,2]
    print(s.removeElement(l,2),l)
