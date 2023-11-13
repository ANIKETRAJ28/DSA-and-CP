#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/network-delay-time/description/

class Solution
{
public:
#define pp pair<int, int>
    vector<list<pp>> graph;
    void add_edge(int src, int dst, int wgt)
    {
        graph[src].push_back({dst, wgt});
    }
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        graph.resize(n + 1, list<pp>());
        vector<int> ans(n + 1, INT_MAX);
        unordered_set<int> visited;
        for (int i = 0; i < times.size(); i++)
        {
            add_edge(times[i][0], times[i][1], times[i][2]);
        }
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, k});
        ans[k] = 0;
        while (not pq.empty())
        {
            pp node = pq.top();
            int src = node.second;
            int srcWgt = node.first;
            pq.pop();
            if (visited.count(src))
                continue;
            visited.insert(src);
            for (auto neighbour : graph[src])
            {
                int dst = neighbour.first;
                int wgt = neighbour.second;
                if (visited.count(dst) and srcWgt + wgt < ans[dst])
                {
                    ans[dst] = srcWgt + wgt;
                    pq.push({ans[dst], dst});
                }
            }
        }
        int maxi = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            maxi = max(maxi, ans[i]);
        }
        return (maxi == INT_MAX) ? -1 : maxi;
    }
};

int main()
{

    return 0;
}