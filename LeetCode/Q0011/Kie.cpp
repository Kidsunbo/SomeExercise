#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        auto right = static_cast<int>(height.size()-1);
        auto left = 0;
        auto water = 0;
        while(left<right) {
            auto h = min(height[left],height[right]);
            water = max(h*(right-left),water);
            while(height[left]<=h) left++;
            while(height[right]<=h) right--;
        }
        return water;
    }
};

int main() {
    Solution s;
    auto v = vector<int>{1,8,6,2,5,4,8,3,7};
    cout<<s.maxArea(v)<<endl;

    return 0;
}