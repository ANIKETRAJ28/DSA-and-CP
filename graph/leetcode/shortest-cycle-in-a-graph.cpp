#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/shortest-cycle-in-a-graph/description/

class Solution {
public:
    #define pp pair<int, int>
    vector<list<int>> graph;
    void add_edge(int src, int dst) {
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }
    int bfs(int src, int n) {
        int ans = INT_MAX;
        vector<int> par(n, -1), dis(n, INT_MAX);
        dis[src] = 0;
        queue<int> qu;
        qu.push(src);
        while(!qu.empty()) {
            int curr = qu.front();
            qu.pop();
            for(auto neig : graph[curr]) {
                if(par[neig] == curr) continue;
                if(dis[neig] == INT_MAX) {
                    dis[neig] = 1 + dis[curr];
                    par[neig] = curr;
                    qu.push(neig);
                } else if(par[curr] != neig and par[neig] != curr) {
                    ans = min(ans, dis[curr] + dis[neig]+1);
                }
            }
        }
        return ans;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        graph.resize(n, list<int> ());
        for(int i = 0 ; i < edges.size() ; i++) {
            add_edge(edges[i][0], edges[i][1]);
        }
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++) {
            ans = min(ans, bfs(i, n));    
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    
    return 0;
}