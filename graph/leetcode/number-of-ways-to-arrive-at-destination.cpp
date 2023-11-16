#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution
{
public:
#define pp pair<ll, ll>
    vector<list<pp>> graph;
    int countPaths(int n, vector<vector<int>> &roads)
    {
        graph.resize(n, list<pp>());
        for (int i = 0; i < roads.size(); i++)
        {
            graph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<ll> dist(n, LONG_MAX);
        vector<ll> cnt(n, 1);
        unordered_set<ll> visited;
        pq.push({0, 0});
        dist[0] = 0;
        while (not pq.empty())
        {
            pp node = pq.top();
            pq.pop();
            ll prnt = node.second;
            ll prntDis = node.first;
            if (visited.count(prnt))
            {
                continue;
            }
            visited.insert(prnt);
            for (auto neighbour : graph[prnt])
            {
                ll child = neighbour.first;
                ll childDis = neighbour.second;
                if (childDis + prntDis < dist[child])
                {
                    dist[child] = childDis + prntDis;
                    cnt[child] = cnt[prnt];
                    pq.push({dist[child], child});
                }
                else if (childDis + prntDis == dist[child])
                {
                    cnt[child] = (cnt[child] + cnt[prnt]) % mod;
                }
            }
        }
        return cnt[n - 1] % mod;
    }
};

int main()
{

    return 0;
}