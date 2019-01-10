#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target)
    {
        unordered_map<int,int> hash;
        vector<int> result;
        for(int i=0;i< nums.size(); i++){
            int complement = target-nums[i];
            if(hash.find(complement)!=hash.end()){
                result.push_back(hash.at(complement));
                result.push_back(i);
                return result;
            }
            hash[nums[i]]=i;
        }
        return result;
    }
};

int main() {
    Solution s;
    auto a = s.twoSum({3,2,4},6);
    for(auto i : a) cout<<i<<endl;
    return 0;
}