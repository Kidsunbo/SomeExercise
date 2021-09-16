class Solution:
    def exist(self, board, word):
        ab_map = {}

        def dfs(length, x, y):
            v = ab_map.get((x, y, length), 0)
            if v >= 4:
                return False
            ab_map[(x, y, length)] = v + 1

            if length == len(word):
                return True

            if 0 <= x < len(board) and 0 <= y < len(board[0]) and board[x][y] == word[length]:
                board[x][y] = ""
                for i, j in ((-1, 0), (0, -1), (0, 1), (1, 0)):
                    if dfs(length + 1, x + i, y + j):
                        return True
                board[x][y] = word[length]
            return False

        for i in range(len(board)):
            for j in range(len(board[i])):
                if dfs(0, i, j):
                    return True
        return False


if __name__ == '__main__':
    s = Solution()
    board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
    print(s.exist(board, "SEE"))
