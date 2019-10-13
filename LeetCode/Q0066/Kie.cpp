#include <iostream>
#include <vector>
using namespace std;

//Time: 100%  Memory: 83.61%
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty()) return digits;
        int i=digits.size()-1;
        for(;i>=0;i--){
            if(digits[i]==9){
                digits[i]=0;
            }
            else {
                digits[i]++;
                break;
            }
        }
        if(i==-1){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};

template <typename T>
ostream& operator<<(ostream& os,const vector<T>& vec){
    if(vec.empty()) return os;
    for(int i=0;i<vec.size()-1;i++){
        cout<<vec[i]<<", ";
    }
    cout<<vec.at(vec.size()-1);
    return os;
}

int main() {
    Solution s;
    vector<int> vec{9,9,9,9};
    cout<<s.plusOne(vec)<<endl;
    return 0;
}