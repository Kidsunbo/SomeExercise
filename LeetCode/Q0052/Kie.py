class Solution:
    def totalNQueens(self, n: int) -> int:
        result = 0

        # [[0]]*10 will shallow copy the inner list ten times, so it can't be used here
        board = [[0] * n for i in range(n)]

        def findAll(board, row, current_col):
            if row == n:
                nonlocal result
                result += 1
                return
            col = findNext(board, row, current_col)
            if col == -1:
                return
            while True:
                fill(board, row, col)
                findAll(board, row + 1, 0)
                unfill(board, row, col)
                col = findNext(board, row, col+1)
                if col == -1:
                    return

        def findNext(board, row, start):
            for i, con in enumerate(board[row][start:]):
                if con == 0:
                    return i+start
            return -1

        def fill(board, row, col):
            board[row][col] += n
            for r in range(row + 1, n):
                board[r][col] += 1
                if col - r + row >= 0: board[r][col - r + row] += 1
                if col + r - row < n: board[r][col + r - row] += 1

        def unfill(board, row, col):
            board[row][col] -= n
            for r in range(row + 1, n):
                board[r][col] -= 1
                if col - r + row >= 0: board[r][col - r + row] -= 1
                if col + r - row < n: board[r][col + r - row] -= 1

        findAll(board,0,0)
        return result


if __name__ == '__main__':
    s = Solution()
    print(s.totalNQueens(10))
