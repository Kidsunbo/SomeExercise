#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		return allRows(board) && allColumns(board) && allBlocks(board);
	}

	bool allRows(vector<vector<char>>& board) {
		for (auto i : board) {
			int arr[10] = {0};
			for (auto j : i) {
				if (j != '.'&&arr[j-'1'] == 1) return false;
				else if (j != '.') arr[j - '1'] = 1;
			}
		}
		return true;
	}

	bool allColumns(vector<vector<char>>& board) {
		for (int i = 0;i < 9;i++) {
			int arr[10] = { 0 };
			for (int j = 0;j < 9;j++) {
				if (board[j][i] != '.'&&arr[board[j][i] -'1'] == 1) return false;
				else if (board[j][i] != '.') arr[board[j][i] -'1'] = 1;
			}
		}
		return true;
	}

	bool allBlocks(vector<vector<char>>& board) {
		for (int i = 0;i < 3;i++) {
			for (int j = 0;j < 3;j++) {
				int arr[10] = { 0 };

				for (int n = 0;n < 3;n++) {
					for (int m = 0;m < 3;m++) {
						if (board[i * 3 + n][j * 3 + m] != '.'&&arr[board[i * 3 + n][j * 3 + m]-'1'] == 1) return false;
						else if (board[i * 3 + n][j * 3 + m] != '.') arr[board[i * 3 + n][j * 3 + m] - '1'] = 1;
					}
				}
			}
		}
		return true;
	}
};


int main() {
	
	vector<vector<char>> b = {
		{ '5','3','.','.','7','.','.','.','.' },
		{ '6','.','.','1','9','5','.','.','.' },
		{ '.','9','8','.','.','.','.','6','.' },
		{ '8','.','.','.','6','.','.','.','3' },
		{ '4','.','.','8','.','3','.','.','1' },
		{ '7','.','.','.','2','.','.','.','6' },
		{ '.','6','.','.','.','.','2','8','.' },
		{ '.','.','.','4','1','9','.','.','5' },
		{ '.','.','.','.','8','.','.','7','9' }
	};
	cout << std::boolalpha << Solution().isValidSudoku(b) << endl;

	cin.get();
	return 0;
}

