#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    /**
     * This one use non constant space, so comment it.
     * @param nums The array
     * @return  The first needed positive number
     */

//    int firstMissingPositive(vector<int>& nums) {
//        vector<bool> temp(nums.size());
//        for (auto i:nums) {
//            if (i > 0 && i <= nums.size()) {
//                temp[i - 1] = true;
//            }
//        }
//        for (auto i = 0; i < temp.size(); i++) {
//            if (!temp[i]) {
//                return i + 1;
//            }
//        }
//        return temp.size() + 1;
//    }


    int firstMissingPositive(vector<int>& nums) {
        for(auto i = 0;i<nums.size();i++){
            if(nums[i]-1>=0 && nums[i]-1<nums.size()){
                bool flag = false;
                auto temp = nums[nums[i]-1];
                if(nums[i]!=temp) flag = true;
                nums[nums[i]-1]=nums[i];
                nums[i]=temp;
                if(flag) i--;
            }
        }
        for(auto i=0;i<nums.size();i++){
            if(nums[i]!=i+1) return i+1;
        }
        return nums.size()+1;
    }
};

int main() {
    vector v{1,3,4,-1,1};
    std::cout << Solution().firstMissingPositive(v) << std::endl;
    return 0;
}