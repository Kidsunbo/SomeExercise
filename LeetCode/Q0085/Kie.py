from typing import List


class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0:
            return 0
        height = len(matrix)
        width = len(matrix[0])

        new_matrix = [[None for i in range(width)] for j in range(height)]
        for i in range(height):
            for j in range(width):
                if i == 0:
                    if matrix[i][j] == '1':
                        new_matrix[i][j] = 1
                    else:
                        new_matrix[i][j] = 0
                else:
                    if matrix[i][j] == '1':
                        new_matrix[i][j] = new_matrix[i - 1][j] + 1
                    else:
                        new_matrix[i][j] = 0
        print(new_matrix)
        result = 0
        for row in new_matrix:
            result = max(result, self.large_rectangle(row))

        return result

    def large_rectangle(self, row):
        stack = []
        max_rectangle = 0
        for i, value in enumerate(row):
            if not stack:
                stack.append((i, value))
            else:
                left_most = -1
                while stack and stack[-1][1] > value:
                    top = stack.pop()
                    left_most = top[0]
                    max_rectangle = max(max_rectangle, (i - top[0]) * top[1])
                stack.append((i if left_most == -1 else left_most, value))
        while stack:
            top = stack.pop()
            max_rectangle = max(max_rectangle, (len(row) - top[0]) * top[1])
        return max_rectangle


if __name__ == '__main__':
    s = Solution()
    print(s.maximalRectangle([["0"]]))
    # print(s.large_rectangle([3, 1, 3, 2, 2]))
