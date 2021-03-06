#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

void print(vector<vector<int>>& temp) {
    cout << endl << "----------DEBUG----------" << endl;
    for (auto& i : temp) {
        for (auto& j : i) cout << j << " ";
        cout << endl;
    }
    cout << "------------------------" << endl;
}


// Non recursive version
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> chessBoard(n,vector<int>(n,0));
        vector<int> allIndex(n,-1);
        vector<vector<string>> result;

        for(int row = 0,col = 0;row<n;){
            for(col = allIndex[row]+1;col<n;col++){
                if(chessBoard[row][col]==0){
                    //Fill
                    chessBoard[row][col] += n;
                    for (int temp_row = row + 1; temp_row < n; temp_row++) {
                        chessBoard[temp_row][col]++;
                        if (col + temp_row - row < n) chessBoard[temp_row][col + temp_row - row]++;
                        if (col - temp_row + row >= 0) chessBoard[temp_row][col - temp_row + row]++;
                    }
                    //End Fill
                    allIndex[row] = col;
                    row++;
                    break;
                }
            }
            if(row==n){
                vector<string> vec;
                vec.reserve(n);
                for (auto &i : chessBoard) {
                    stringstream ss;
                    for (auto &j : i) {
                        if (j < n) ss << '.';
                        else ss << 'Q';
                    }
                    vec.push_back(ss.str());
                }
                result.push_back(vec);
                row--;
                chessBoard[row][col]-=n;
            }

            if(col==n) {
                bool found = false;
                while (!found) {
                    allIndex[row]=-1;
                    row--;
                    if(row<0) return result;
                    //Unfill
                    int temp_col = allIndex[row];
                    chessBoard[row][temp_col] -= n;
                    for (int temp_row = row + 1; temp_row < n; temp_row++) {
                        chessBoard[temp_row][temp_col]--;
                        if (temp_col + temp_row - row < n) chessBoard[temp_row][temp_col + temp_row - row]--;
                        if (temp_col - temp_row + row >= 0) chessBoard[temp_row][temp_col - temp_row + row]--;
                    }
                    //End Unfill

                    //Find next
                    for (col = allIndex[row] + 1; col < n; col++) {
                        if (chessBoard[row][col] == 0) {
                            found = true;
                            break;
                        }
                    }
                    //End find next
                }
            }

        }
        return result;
    }
};

// //Recursive version
//class Solution {
//public:
//    vector<vector<string>> solveNQueens(int n) {
//        vector<vector<int>> chessBoard(n,vector<int>(n,0));
//        vector<vector<string>> result;
//        solve(chessBoard,result,0,-1,n);
//        return result;
//    }
//
//    void solve(vector<vector<int>>& chessBoard,vector<vector<string>>& result,int row,int current_col,int n) {
//        if (row == n) {
//            vector<string> vec;
//            vec.reserve(n);
//            for (auto &i : chessBoard) {
//                stringstream ss;
//                for (auto &j : i) {
//                    if (j < n) ss << '.';
//                    else ss << 'Q';
//                }
//                vec.push_back(ss.str());
//            }
//            result.push_back(vec);
//            return;
//        }
//        auto res = findNext(chessBoard, row, current_col + 1, n);
//        if (res == -1) {
//            return;
//        }
//        while (true) {
//            fill(chessBoard,row,res,n);
//            solve(chessBoard,result,row+1,-1,n);
//            unfill(chessBoard,row,res,n);
//            res = findNext(chessBoard, row, res+1, n);
//            if (res == -1) {
//                return;
//            }
//        }
//
//    }
//
//    int findNext(vector<vector<int>>& chessBoard,int row, int start,int n){
//        if(start==n) return -1;
//        for(;start<n;start++){
//            if(chessBoard[row][start]==0) return start;
//        }
//        return -1;
//    }
//
//    void fill(vector<vector<int>>& chessBoard,int row,int col,int n) {
//        chessBoard[row][col] += n;
//        for (int temp_row = row + 1; temp_row < n; temp_row++) {
//            chessBoard[temp_row][col]++;
//            if (col + temp_row - row < n) chessBoard[temp_row][col + temp_row - row]++;
//            if (col - temp_row + row >= 0) chessBoard[temp_row][col - temp_row + row]++;
//        }
//    }
//    void unfill(vector<vector<int>>& chessBoard,int row,int col,int n) {
//        chessBoard[row][col] -= n;
//        for (int temp_row = row + 1; temp_row < n; temp_row++) {
//            chessBoard[temp_row][col]--;
//            if (col + temp_row - row < n) chessBoard[temp_row][col + temp_row - row]--;
//            if (col - temp_row + row >= 0) chessBoard[temp_row][col - temp_row + row]--;
//        }
//    }
//};



int main() {
    Solution s;
    auto res = s.solveNQueens(8);
    for (auto& i : res) {
        for (auto& j : i) {
            cout << j << endl;
        }
        cout << "-----------------------" << endl;
    }
    cin.get();
    return 0;
}