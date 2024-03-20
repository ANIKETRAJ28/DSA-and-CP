#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

class Solution {
public:
    struct Edge {
        int src, dst, wts;
    };

    static bool cmp(Edge &e1, Edge &e2) {
        return e1.wts < e2.wts;
    }

    int find(vector<int> &parent, int n) {
        return parent[n] = (parent[n] == n) ? n : find(parent, parent[n]);
    }
    void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);
        if(a == b) return;
        if(rank[a] >= rank[b]) {
            parent[b] = a;
            rank[a]++;
        } else {
            parent[b] = a;
            rank[b]++;
        }
    }

    int kruskals(vector<Edge> &graph, int n) {
        vector<int> parent(n), rank(n, 1);
        for(int i = 0 ; i < n ; i++) parent[i] = i;
        sort(graph.begin(), graph.end(), cmp);
        int ans = 0;
        for(int i = 0 ; i < graph.size() ; i++) {
            int src = find(parent, graph[i].src);
            int dst = find(parent, graph[i].dst);
            if(src == dst) continue;
            Union(parent, rank, src, dst);
            ans += graph[i].wts;
        }
        return ans;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> graph;
        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                int srci = points[i][0];
                int srcj = points[i][1];
                int dsti = points[j][0];
                int dstj = points[j][1];
                graph.push_back({i, j, abs(srci - dsti) + abs(srcj - dstj)});
            }
        }
        return kruskals(graph, n);
    }
};

int main()
{

    return 0;
}