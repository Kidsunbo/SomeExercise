#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        for(int diff = 0;;diff++){
            for(auto first=0;first<nums.size()-2;first++) {
                for (auto second = first + 1; second < nums.size() - 1; second++) {
                    for (auto third = second + 1; third < nums.size(); third++) {
                        if (abs(nums[first] + nums[second] + nums[third] - target) == diff)
                            return nums[first] + nums[second] + nums[third];
                    }
                }
            }
        }
    }
};

int main() {
    auto s = Solution();
    vector v{0,2,1,-3};
    cout<<s.threeSumClosest(v,1)<<endl;
    return 0;
}
