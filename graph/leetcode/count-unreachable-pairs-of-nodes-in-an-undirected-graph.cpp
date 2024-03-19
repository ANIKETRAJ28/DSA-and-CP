#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

class Solution {
public:
    vector<int> parent, size;
    int find(int n) {
        return parent[n] = (parent[n] == n) ? n : find(parent[n]);
    }
    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(size[a] >= size[b]) {
            size[a] += size[b];
            parent[b] = a;
        } else {
            size[b] += size[a];
            parent[a] = b;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0 ; i  < n ; i++) {
            parent[i] = i;
        }
        for(int i = 0 ; i < edges.size() ; i++) {
            Union(edges[i][0], edges[i][1]);
        }
        long long cnt = -1;
        for(int i = 0 ; i < n ; i++) {
            if(parent[i] == i) {
                if(cnt == -1) {
                    cnt = size[i];
                } else {
                    ans += (cnt*size[i]);
                    cnt += size[i];
                }
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}