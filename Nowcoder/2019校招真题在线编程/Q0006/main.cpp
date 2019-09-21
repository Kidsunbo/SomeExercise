#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Just figure out how many intersection in a rectangle.
// One can loop all the possible intersection and then do the thing mentioned above.
int main() {
    int n = 0;
    cin>>n;
    vector<int> x1(n);
    vector<int> y1(n);
    vector<int> x2(n);
    vector<int> y2(n);
    for(int i=0;i<n;i++) {
        cin>>x1[i];
    }
    for(int i=0;i<n;i++){
        cin>>y1[i];
    }
    for(int i=0;i<n;i++) {
        cin>>x2[i];
    }
    for(int i=0;i<n;i++){
        cin>>y2[i];
    }
    int maxNum = 0;
    for(auto& x : x1){ // x is of the possible intersection
        for(auto& y:y1){ // y is of the possible intersection
            int temp = 0;
            for(int i=0;i<n;i++){ // Loop all the rectangles
                /**
                 * Pay attention to the greater than and less than operators
                 * I should guarantee that when two rects are next to each other,
                 * I only count this into one rectangle.
                 */
                if(x>=x1[i]&&y>=y1[i]&&x<x2[i]&y<y2[i])// if the intersection is in the rectangle
                    temp++;
            }
            maxNum = temp>maxNum?temp:maxNum;
        }
    }
    cout<<maxNum;
    return 0;
}