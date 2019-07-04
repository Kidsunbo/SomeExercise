class Solution:
    def permuteUnique(self, nums: list) -> list:
        # This is the algorithm inspired by others
        picked = [False]*len(nums)
        result = []
        def dfs(step,current,picked):
            if step==len(nums):
                result.append(current)
                return
            used = []
            for i in range(len(picked)):
                if not picked[i] and nums[i] not in used:
                    picked[i] = True
                    used.append(nums[i])
                    dfs(step+1,current+[nums[i]],picked)
                    picked[i]=False
        dfs(0,[],picked)
        return result

    '''
    # This is the algorithm come up by myself
        result = []
        index = [0]*len(nums)
        finish = False
        while not finish:
            picked = [False] * len(nums)
            temp = []
            for i in index:
                temp.append(self.findAndMark(nums, i, picked))

            for i in range(len(index)-1,-1,-1):
                if index[i]<len(index)-1-i:
                    index[i]+=1
                    break
                else:
                    index[i]=0
                    if i==0:
                        finish = True

            result.append(temp)
        new_result = []
        for i in result:
            if i in new_result:
                continue
            new_result.append(i)
        return new_result


    def findAndMark(self,nums,ind,picked):
        for i,content in enumerate(picked):
            if ind==0 and not content:
                picked[i] = True
                return nums[i]
            if not content:
                ind -=1
                continue
    '''








if __name__ == '__main__':
    s = Solution()
    print("\n".join(list(map(lambda x: ",".join(map(lambda y: str(y), x)), s.permuteUnique([1,1,2,3,4,5,6,7,8,9])))))
