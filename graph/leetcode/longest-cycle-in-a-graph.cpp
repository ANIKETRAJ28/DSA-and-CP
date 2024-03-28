#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/longest-cycle-in-a-graph/description/

class Solution {
public:
    int dfs(vector<int>& edges, int src, vector<bool> &vis, int cnt) {
        vis[src] = 1;
        cnt++;
        if(edges[src] == -1 or vis[edges[src]]) return cnt;
        return dfs(edges, edges[src], vis, cnt);
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> indegree(n, 0);
        for(int i = 0 ; i < n ; i++)
            if(edges[i] != -1)
                indegree[edges[i]]++;
        queue<int> qu;
        for(int i = 0 ; i < n ; i++) 
            if(indegree[i] == 0)
                qu.push(i);
        while(!qu.empty()) {
            int curr = qu.front();
            qu.pop();
            if(edges[curr] == -1) continue;
            indegree[edges[curr]]--;
            if(indegree[edges[curr]] == 0) qu.push(edges[curr]);
        }
        vector<bool> vis(n, 0);
        int maxi = -1;
        for(int i = 0 ; i < n ; i++) {
            if(vis[i] != 0) continue;
            if(indegree[i] == 0 or vis[i]) continue;
            maxi = max(maxi, dfs(edges, i, vis, 0));
        }
        return maxi == 0 ? -1 : maxi;
    }
};

int main() {
    
    return 0;
}