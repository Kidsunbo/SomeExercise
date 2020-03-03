#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size()==0) return word2.length();
        if(word2.size()==0) return word1.length();
        vector<vector<int>> table(word1.length()+1,vector<int>(word2.length()+1));
        // First row
        for(int i = 0;i<word2.size()+1;i++) table[0][i]=i;
        // First column
        for(int i=0;i<word1.size()+1;i++) table[i][0] = i;

        for(int i=0;i<word1.size();i++){
            for(int j=0;j<word2.size();j++){
                int flag = word1[i]==word2[j]?0:1;
                int m = min(min(table[i][j]+flag,table[i+1][j]+1),table[i][j+1]+1);
                table[i+1][j+1] = m;
            }
        }

        return table[word1.size()][word2.size()];

    }
};

int main() {
    Solution s;
    cout<<s.minDistance("pneumonoultramicroscopicsilicovolcanoconiosis"
                        ,"ultramicroscopically")<<endl;
    return 0;
}
