#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/redundant-connection/submissions/

class Solution
{
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x)
    {
        return parent[x] = (x == parent[x]) ? x : find(parent[x]);
    }
    bool flag = false;
    void Union(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            flag = true;
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
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            Union(edges[i][0], edges[i][1]);
            if (flag == true)
            {
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
                return ans;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}