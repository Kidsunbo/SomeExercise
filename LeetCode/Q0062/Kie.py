# # Time 76.35%  Memory 5.77%
# class Solution:
#     def getResult(self,x,y,matrix):
#         if matrix[y][x]!=-1:
#             return matrix[y][x]
#         matrix[y][x]=self.getResult(x-1,y,matrix)+self.getResult(x,y-1,matrix)
#         return matrix[y][x]
#
#     def uniquePaths(self, m: int, n: int) -> int:
#         mat = [[-1]*m for i in range(n)]
#         for i in range(m):
#             mat[0][i]=1
#         for i in range(n):
#             mat[i][0]=1
#         return self.getResult(m-1,n-1,mat)

# Time 43.32%  Memory 5.77%
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        mat = [[1]*m for i in range(n)]
        for i in range(1,m):
            for j in range(1,n):
                mat[j][i] = mat[j-1][i]+mat[j][i-1]
        return mat[n-1][m-1]

if __name__ == '__main__':
    s = Solution()
    for i in range(1,10):
        print(f'{i},{i}->{s.uniquePaths(i,i)}')