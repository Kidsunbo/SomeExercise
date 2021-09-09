#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;

        std::function<void(int)> dfs = [&](int start){
            result.push_back(cur);
            for(int i = start; i<nums.size();i++){
                cur.push_back(nums[i]);
                dfs(i+1);
                cur.pop_back();
            }
        };
        dfs(0);
        return result;
    }
};

void print(const vector<vector<int>>& v){
    for(const auto& i: v){
        std::string sep;
        std::cout<<"[";
        for(auto j:i){
            std::cout<<sep<<j;
            sep = ", ";
        }
        std::cout<<"]"<<std::endl;
    }
}

int main(){
    Solution s;
    std::vector<int> nums = {1,2,3,4,5,6};
    print(s.subsets(nums));
    return 0;
}
