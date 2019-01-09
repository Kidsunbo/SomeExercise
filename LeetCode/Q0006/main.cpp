#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<int> vec;
        for(int i=0;i<s.length()+numRows;i+=((numRows-1)*2==0?1:(numRows-1)*2)){
            vec.push_back(i);
        }
        stringstream ss;
        for(auto i : vec){
            i<s.length() && ss<<s[i];
        }
        for(auto row = 1;row<numRows-1;row++) {
            for (auto i = 0; i < vec.size(); i++) {
                vec[i] + row < s.length() && ss << s[vec[i]+row];
                vec[i+1] - row < s.length() && i+1<vec.size() && ss<<s[vec[i+1]-row];
            }
        }
        if(numRows!=1) {
            for (auto i:vec) {
                i + numRows - 1 < s.length() && ss << s[i + numRows - 1];
            }
        }
        return ss.str();
    }
};

int main() {

    Solution s;
    cout<<s.convert("ABCD",3)<<endl;
    return 0;
}

/*
 * p       p
 * p     p
 * p   p
 * p p
 * p
 *"PAHNAPLSIIGYIR"
 *
 */