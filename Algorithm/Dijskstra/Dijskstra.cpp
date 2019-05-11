#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <sstream>

using namespace std;

tuple<vector<int>,vector<int>> dijskstra(vector<vector<int>> graph){
    vector<int> dis(graph.size(),INT_MAX);
    dis[0]=0;
    vector<int> parent(graph.size(),-1);
    auto find_min = [&](auto v,auto p){
        int index=0;
        int min = INT_MAX;
        for(auto i = 0;i<v.size();i++) {
            if (v[i] != 0 && v[i] < min && i!=parent[p]) {
                index = i;
                min = v[index];
            }
        }
        return index;
    };

    int current = 0;
    while(find(dis.begin(),dis.end(),INT_MAX)!=dis.end()){
        for(int i = 0;i<graph.size();i++){
            if(graph[current][i]!=0 && dis[i]>graph[current][i]+dis[current]){
                dis[i]=dis[current]+graph[current][i];
                parent[i]=current;
            }
        }
        current = find_min(graph[current],current);
    }
    return {parent,dis};
}


int main() {

    auto graph = vector<vector<int>>{{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                     {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                     {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                     {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                     {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                     {0, 0, 4, 14, 10, 0, 2, 0, 0},
                                     {0, 0, 0, 0, 0, 2, 0, 1, 6},
                                     {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                     {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    auto index = 7;
    auto i = index-1;
    auto [a,b] = dijskstra(graph);
    stringstream s;
    while(a[i]!=-1){
        s<<i+1<<" >= ";
        i = a[i];
    }
    s<< 1<<endl;
    auto ss = s.str();
    for_each(ss.rbegin(),ss.rend(),[](auto i){cout<<i;});
    cout<<endl;
    cout<<b[index-1]<<endl;

    return 0;
}
