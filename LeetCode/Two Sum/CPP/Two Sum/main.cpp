//
//  main.cpp
//  Two Sum
//
//  Created by 孙博 on 2017/6/18.
//  Copyright © 2017年 孙博. All rights reserved.
//
// https://leetcode.com/problems/two-sum/#/description


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int other = target - nums[i];
            

            if (hash.find(other) != hash.end()) {

                result.push_back(hash[other] + 1);
                result.push_back(i + 1);
                return result;
            }
            
            hash[nums[i]] = i;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> vec{1,5,9,7};
    for(auto i :s.twoSum(vec , 16))
    {
        cout<<i<<endl;
    }
    return 0;
}
