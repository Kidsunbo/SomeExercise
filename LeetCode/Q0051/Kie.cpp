#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> temp(n,vector<char>(n,'.'));
        vector<vector<string>> result;
        solve(temp,result,0,n);
        return result;
    }

    void solve(vector<vector<char>>& temp,vector<vector<string>>& result,int row,const int& max){
        if(row==max){
            if(checkValid(temp)){
                vector<string> res;
                res.reserve(temp.size());
                for(auto& vec:temp){
                    res.emplace_back(vec.begin(),vec.end());
                }
                result.push_back(res);
                return;
            }
            else return;
        }
        else{
            for(int i=0;i<temp.size();i++){
                if(i>0)temp[row][i-1]='.';
                temp[row][i]='Q';
                solve(temp,result,row+1,max);
            }
            temp[row][temp[row].size()-1]='.';
        }
    }

    bool checkValid(const vector<vector<char>>& vec){
        for(int row = 0;row<vec.size();row++){
            for(int col=0;col<vec[row].size();col++){
                if(vec[row][col]=='Q'){
                    // check up side
                    for(int i=row-1,left = col-1,right = col+1;i>=0;i--,left--,right++){
                        if(vec[i][col]=='Q') return false;
                        if(left>=0&&vec[i][left]=='Q') return false;
                        if(right<vec.size()&&vec[i][right]=='Q') return false;
                    }
                    // check down side
                    for(int i=row+1,left=col-1,right=col+1;i<vec.size();i++,left--,right++){
                        if(vec[i][col]=='Q') return false;
                        if(left>=0&&vec[i][left]=='Q') return false;
                        if(right<vec.size()&&vec[i][right]=='Q') return false;
                    }

                }
            }
        }
        return true;
    }
};



void print(vector<vector<char>>& temp){
    cout<<endl<<"----------DEBUG----------"<<endl;
    for(auto& i:temp){
        cout<<string(i.begin(),i.end())<<endl;
    }
    cout<<"------------------------"<<endl;
}

int main() {
    Solution s;
    auto res = s.solveNQueens(9);
    for(auto& i:res){
        for(auto& j:i){
            cout<<j<<endl;
        }
        cout<<"-----------------------"<<endl;
    }
    cin.get();
    return 0;
}