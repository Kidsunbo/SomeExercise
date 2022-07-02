#include <vector>
#include <stack>
#include <list>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        stack<pair<int,int>> st;  //first: height of current, second: left extreme index.
        int answer = 0;
        for(int i=0;i< heights.size(); i++){
            if(st.empty()){
                st.push({heights[i], i});
            }else{
                auto left_extreme_index = -1;
                while(!st.empty() && st.top().first > heights[i]){
                    auto top = st.top();
                    st.pop();
                    left_extreme_index = top.second;
                    answer = max(answer, (i-top.second)*top.first);
                }
                st.push({heights[i], left_extreme_index==-1?i:left_extreme_index});
            }
        }

        while(!st.empty()){
            auto top = st.top();
            st.pop();
            answer = max(answer, (static_cast<int>(heights.size())-top.second)*top.first);
        }
        return answer;
    }
};

int main(){
    std::vector vec{2,1,2};
    std::cout<<Solution().largestRectangleArea(vec)<<std::endl;
    return 0;
}