#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/description/

class Solution {
public:
    #define pp pair<int, int>
    vector<list<pp>>graph;

    void add_list(int src, int dst, int wts) {
        graph[src].push_back({dst, wts});
        graph[dst].push_back({src, wts});
    }

    vector<int> prims(int src, int n, vector<int> &disappear) {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        unordered_set<int> visited;
        vector<int> wts(n, INT_MAX), parent(n);
        vector<int> time(n, INT_MAX);
        for(int i = 0 ; i < n ; i++) parent[i] = i;
        wts[src] = 0;
        time[src] = 0;
        pq.push({0, src});
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int par = node.second;
            int wt = node.first;
            if(visited.count(par)) continue;
            time[par] = wt;
            visited.insert(par);
            for(auto neig : graph[par]) {
                if(!visited.count(neig.first) and wt+neig.second < disappear[neig.first]) {
                    wts[neig.first] = neig.second+wt;
                    parent[neig.first] = par;
                    pq.push({neig.second+wt, neig.first});
                }
            }
        }
        return time;
    }
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        int m = edges.size();
        graph.resize(n, list<pp>());
        for(int i = 0 ; i < m ; i++) {
            add_list(edges[i][0], edges[i][1], edges[i][2]);
        }
        vector<int> ans = prims(0, n, disappear);
        for(int i = 0 ; i < n ; i++) {
            if(ans[i] == INT_MAX) ans[i] = -1;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}