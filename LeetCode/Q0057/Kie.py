class Solution:
    def insert(self, intervals, newInterval):
        if len(intervals) == 0: return [newInterval]
        if len(newInterval) == 0: return intervals
        intervals.append(newInterval)
        intervals = sorted(intervals, key=lambda x: x[0])
        result = [intervals[0]]
        for i in intervals[1:]:
            last = result[-1]
            if last[1] >= i[0]:
                last[1] = last[1] if last[1] > i[1] else i[1]
            else:
                result.append(i)
        return result



if __name__ == '__main__':
    s = Solution()
    print(s.insert(intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]))
