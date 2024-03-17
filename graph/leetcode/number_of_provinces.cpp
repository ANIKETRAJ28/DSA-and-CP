#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/number-of-provinces/description/

// dfs
class Solution {
public:
    unordered_set<int> visited;
    void dfs(vector<vector<int>>& graph, int idx) {
        int n = graph.size();
        for(int i = 0 ; i < n ; i++) {
            if(visited.find(i) != visited.end() or i == idx or graph[idx][i] == 0) continue;
            visited.insert(i);
            dfs(graph, i);
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            if(visited.find(i) != visited.end()) continue;
            cnt++;
            visited.insert(i);
            dfs(isConnected, i);
        }
        return cnt;
    }
};

// bfs
class Solution {
public:
    unordered_set<int> visited;
    void bfs(vector<vector<int>>& graph, int idx) {
        int n = graph.size();
        queue<int> qu;
        qu.push(idx);
        for(int i = 0 ; i < n ; i++) {
            if(visited.find(i) != visited.end() or i == idx or graph[idx][i] == 0) continue;
            visited.insert(i);
            qu.push(i);
        }
        while(not qu.empty()) {
            int prnt = qu.front();
            qu.pop();
            for(int i = 0 ; i < n ; i++) {
                if(visited.find(i) != visited.end() or i == prnt or graph[prnt][i] == 0) continue;
                visited.insert(i);
                qu.push(i);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            if(visited.find(i) != visited.end()) continue;
            cnt++;
            visited.insert(i);
            bfs(isConnected, i);
        }
        return cnt;
    }
};

// dsu
class Solution {
public:
    int find(vector<int> &parent, int n) {
        return parent[n] = (parent[n] == n) ? n : find(parent, parent[n]);
    }
    void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);
        if(a == b) return;
        if(rank[a] >= rank[b]) {
            rank[a]++;
            parent[b] = a;
        } else {
            rank[b]++;
            parent[a] = b;
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> rank(n, 1);
        vector<int> parent(n);
        for(int i = 0 ; i < n ; i++) parent[i] = i;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(i == j or isConnected[i][j] == 0) continue;
                Union(parent, rank, i, j);
            }
        }
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            if(parent[i] == i) cnt++;
        }
        return cnt;
    }
};

int main()
{

    return 0;
}