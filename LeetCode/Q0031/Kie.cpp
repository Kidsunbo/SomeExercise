#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2) return;
		auto last = nums.size() - 1;
		for (;last > 0;last--) {
			if (nums[last] <= nums[last - 1]) continue;
			else break;
		}
		
		if (last == 0 && nums[1] <= nums[0]) {
			std::reverse(nums.begin(), nums.end());
			return;
		}
		last--;
		int next = last+1;
		for (int i = next;i < nums.size();i++) {
			if (nums[i] > nums[last]) next = i;
		}
		auto temp = nums[last];
		nums[last] = nums[next];
		nums[next] = temp;

		auto lastIter = nums.begin() + last+1;
		std::reverse(lastIter, nums.end());
	}
};

int main() {
	vector<int> v{ 1,3,2};
	Solution s;
	s.nextPermutation(v);

	for (auto i : v) {
		cout << i << "  ";
	}
	cout << endl;

	cin.get();

}