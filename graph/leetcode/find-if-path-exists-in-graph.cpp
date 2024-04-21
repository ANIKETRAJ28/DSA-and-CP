#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-if-path-exists-in-graph/description/

class Solution {
public:
    vector<int> parent, rank;
    int find(int a) {
        return parent[a] =  (parent[a] == a) ? a : find(parent[a]);
    }
    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        if(rank[a] >= rank[b]) {
            rank[a]++;
            parent[b] = a;
        } else {
            rank[b]++;
            parent[a] = b;
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        rank.resize(n, 1);
        for(int i = 0 ; i < n ; i++) parent[i] = i;
        for(int i = 0 ; i < edges.size() ; i++) {
            Union(edges[i][0], edges[i][1]);
        }
        return find(source) == find(destination);
    }
};

int main() {
    
    return 0;
}