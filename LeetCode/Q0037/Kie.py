class Solution:
    def solveSudoku(self, board):
        """
        Do not return anything, modify board in-place instead.
        """
        self.__solveSudokuHelper(board)

    def __solveSudokuHelper(self,board):
        ir,ic=0,0
        for i,j in ((x,y) for x in range(len(board)) for y in range(len(board[0]))):
            ir,ic = i,j
            if board[i][j]==".":
                break
        if ir==8 and ic ==8 and board[ir][ic]!=".":
            return True
        for i in map(str,range(1,10)):
            if self._isValid(board,ir,ic,i):
                board[ir][ic] = i
                if self.__solveSudokuHelper(board):
                    return True
        board[ir][ic] = "."
        return False

    def _isValid(self,board,r,c,s):
        if any(board[r][i]==s for i in range(len(board[r]))): return False
        if any(board[i][c]==s for i in range(len(board))): return False
        br,bc = 3*(r//3), 3*(c//3)
        if any(board[br+n][bc+m]==s for n in range(3) for m in range(3)): return False
        return True

if __name__ == '__main__':

    board = [
      ["5","3",".",".","7",".",".",".","."],
      ["6",".",".","1","9","5",".",".","."],
      [".","9","8",".",".",".",".","6","."],
      ["8",".",".",".","6",".",".",".","3"],
      ["4",".",".","8",".","3",".",".","1"],
      ["7",".",".",".","2",".",".",".","6"],
      [".","6",".",".",".",".","2","8","."],
      [".",".",".","4","1","9",".",".","5"],
      [".",".",".",".","8",".",".","7","9"]
    ]

    s = Solution()
    s.solveSudoku(board)
    print(board)