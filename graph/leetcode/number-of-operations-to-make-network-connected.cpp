#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class Solution
{
public:
    int cycle = 0;
    vector<int> parent, rank;
    int find(int x)
    {
        return (x == parent[x]) ? x : find(parent[x]);
    }
    void Union(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            cycle++;
            return;
        }
        if (rank[x] >= rank[y])
        {
            rank[x]++;
            parent[y] = x;
        }
        else
        {
            rank[y]++;
            parent[x] = y;
        }
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int m = connections.size();
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            Union(connections[i][0], connections[i][1]);
        }
        int cc = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
                cc++;
        }
        return (cycle >= cc - 1) ? cc - 1 : -1;
    }
};

int main()
{

    return 0;
}