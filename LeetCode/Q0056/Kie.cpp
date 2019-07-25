#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.empty()) return result;

        sort(intervals.begin(),intervals.end(),[](auto x1,auto x2){return x1[0]<x2[0];});
        result.push_back(intervals[0]);
        for(size_t i =1;i<intervals.size();i++){
            auto& last = result.back();
            if(last[1]>=intervals[i][0]) last[1]=max(last[1],intervals[i][1]);
            else result.push_back(intervals[i]);
        }
        return result;
    }
};


int main() {
    auto s = Solution();
    vector<vector<int>> testSet = {{4,7},{1,3},{5,9}};
    auto r = s.merge(testSet);
    cout<<"["<<endl;
    for(auto& i : r){
        cout<<"  [";
        for(auto& j : i){
            cout<<j<<",";
        }
        cout<<"]"<<endl;
    }
    cout<<"]"<<endl;
    return 0;
}