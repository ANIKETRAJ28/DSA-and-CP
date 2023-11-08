#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

class Solution
{
public:
    vector<int> parent;
    vector<int> rank;

    int find(int a)
    {
        return parent[a] = (parent[a] == a) ? a : find(parent[a]);
    }

    void Union(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (rank[a] >= rank[b])
        {
            parent[b] = a;
            rank[a]++;
        }
        else
        {
            parent[a] = b;
            rank[b]++;
        }
    }

    int kruskals(vector<vector<int>> &edges)
    {
        int ans = 0;
        int n = edges.size();
        sort(edges.begin(), edges.end());
        for (int i = 0; i < n; i++)
        {
            vector<int> e = edges[i];
            int a = find(e[1]);
            int b = find(e[2]);
            if (a == b)
                continue;
            ans += e[0];
            Union(a, b);
        }
        return ans;
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        vector<vector<int>> edges;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dis, i, j});
            }
        }
        return kruskals(edges);
    }
};

int main()
{

    return 0;
}