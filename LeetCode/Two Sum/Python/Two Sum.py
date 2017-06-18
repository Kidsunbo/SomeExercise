class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        m = {}
        index = 0
        for i in nums:
            difference = target-i
            if difference in m.keys():
                return [m[difference],index]
            m[i]=index
            index+=1


if __name__=="__main__":
    nums = [2, 7, 11, 15]
    target = 9

    s = Solution()
    print(s.twoSum(nums=nums,target=target))