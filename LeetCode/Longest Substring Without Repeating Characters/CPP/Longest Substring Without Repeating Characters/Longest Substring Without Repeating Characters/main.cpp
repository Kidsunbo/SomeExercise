//
//  main.cpp
//  Longest Substring Without Repeating Characters
//
//  Created by 孙博 on 2017/6/18.
//  Copyright © 2017年 孙博. All rights reserved.
//  https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description


#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

// Maybe O(n)?


//It cost 12ms and beats 98.2% CPP subscriber


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> vec;
        int length = 0;
        for(auto c:s){
            auto tempIter = find(vec.cbegin(),vec.cend(),c);
            if(tempIter!=vec.cend()){
                if(length<(vec.size())) length=static_cast<int>(vec.size());
                vec.erase(vec.cbegin(),++tempIter);
                vec.push_back(c);
            }
            else{
                vec.push_back(c);
            }
            
        }
        return length>vec.size()?length:static_cast<int>(vec.size());
        
        
    }
};






int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    cout<<s.lengthOfLongestSubstring("bvbp");
    return 0;
}
