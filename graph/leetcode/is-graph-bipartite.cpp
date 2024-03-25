#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/is-graph-bipartite/description/

class Solution {
public:
    bool bfs(vector<vector<int>>& graph, vector<int> &color, int src, int n) {
        queue<int> qu;
        color[src] = 0;
        qu.push(src);
        while(!qu.empty()) {
            int par = qu.front();
            qu.pop();
            for(auto neig : graph[par]) {
                if(color[neig] == -1) {
                    color[neig] = !color[par];
                    qu.push(neig);
                } else if(color[neig] == color[par]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0 ; i < n ; i++) {
            if(color[i] == -1) {
                if(!bfs(graph, color, i, n)) return false;
            }
        }
        return true;
    }
};

int main() {
    
    return 0;
}