#include <iostream>
#include <vector>
#include <algorithm>  // Used for the other algorithm
using namespace std;

// // This algorithm is much faster even it seems to be silly. It beats 83% while the other beats 29% in time.
//class Solution {
//public:
//    vector<vector<int>> permute(vector<int> nums) {
//        std::sort(nums.begin(),nums.end());
//        int l = fact(nums.size());
//        vector<vector<int>> result(l,vector<int>());
//        for(auto i =0;i<nums.size();i++){
//
//            int ind = 0;
//            int count =fact(nums.size()-1-i);
//            int j = count;
//            for(auto& vec : result){
//                while(std::find(vec.begin(),vec.end(),nums[ind])!=vec.end()){
//                    ind=++ind%nums.size();
//                }
//                vec.push_back(nums[ind]);
//                j--;
//                if(j==0){
//                    j=count;
//                    ind=++ind%nums.size();
//                }
//            }
//        }
//        return result;
//    }
//
//    int fact(int num){
//        if(num<=1) return 1;
//        return fact(num-1)*num;
//    }
//};


class Solution {
public:
    vector<vector<int>> permute(const vector<int>& nums) {
        vector<int> index(nums.size(),0);
        vector<bool> stillThere(nums.size(),true);
        vector<vector<int>> result;
        bool finish=false;
        while(!finish){
            auto v = findNext(nums,index,stillThere,finish);
            result.push_back(v);
        }
        return result;
    }

    vector<int> findNext(const vector<int>& nums,vector<int>& index,vector<bool> stillThere,bool& finish){
        vector<int> result;
        for(int i = 0;i<index.size();i++){
            int ind = index[i];
            int j=0,count = 0;
            for(;j<=ind&&count<stillThere.size();j++){
                if(stillThere[count++]) continue;
                j--;
            }
            result.push_back(nums[count-1]);
            stillThere[count-1]=false;
        }

        for(int i = index.size()-1;i>=0;i--){
            if(index[i]<index.size()-1-i) {
                index[i]++;
                break;
            }
            else{
                index[i]=0;
                if(i==0) finish=true;
            }
        }
        return result;
    }

};


int main() {

    Solution s;
    auto v = s.permute({1,2,3,4,5,6,7,8,9});
    for(auto& i : v) {
        for (auto& j:i) {
            std::cout << j << "  ";
        }
        std::cout<<std::endl;
    }
    cin.get();
    return 0;
}