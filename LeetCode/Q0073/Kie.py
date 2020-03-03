import pprint
import random

class Solution:
    def setZeroes(self, matrix) -> None:
        if len(matrix)==0: return
        # Record if the row or colomn has zero
        row = False
        column = False
        if 0 in matrix[0][1:]:
            row = True
        for i in range(1,len(matrix)):
            if matrix[i][0] ==0:
                column = True
                break

        # Modify the value in first column and the first row if its row and column contain a zero
        for i in range(1,len(matrix)):
            for j in range(1,len(matrix[i])):
                if matrix[i][j]==0:
                    matrix[0][j] = 0
                    matrix[i][0] = 0

        # Change to zero if contains zero for row
        for i in range(1,len(matrix)):
            if matrix[i][0]==0:
                matrix[i] = [0]*len(matrix[i])

        # Change to zero if contains zero for column
        for i in range(1,len(matrix[0])):
            if matrix[0][i]==0:
                for j in range(1,len(matrix)):
                    matrix[j][i] = 0

        # Update the edge situation
        if matrix[0][0] == 0:
            matrix[0] = [0]*len(matrix[0])
            for i in range(1,len(matrix)):
                matrix[i][0] = 0
        else:
            if row:
                matrix[0] = [0]*len(matrix[0])
            if column:
                for i in range(len(matrix)):
                    matrix[i][0] = 0


if __name__ == '__main__':
    s = Solution()
    a = [[random.randint(0,4) for _ in range(5)] for _ in range(5)]
    pprint.pprint(a)
    print()
    s.setZeroes(a)
    pprint.pprint(a)
