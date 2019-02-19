#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        auto index=1;
        auto current = nums[0];
        for(auto i : nums){
            if(current!=i){
                nums[index] = i;
                current=i;
                index++;
            }
        }
        return index;
    }
};

int main() {
    Solution s;
    vector<int> vec{1,2,2,2,3,3,4,4,4,5};
    auto len = s.removeDuplicates(vec);
    for(auto i = 0;i<len;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}