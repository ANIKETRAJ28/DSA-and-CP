#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://www.hackerrank.com/challenges/primsmstsub/problem

vec<list<pp>> graph;

void add(int src, int dst, int wgt, bool bi_direc = true)
{
    graph[src].push_back({dst, wgt});
    if (bi_direc)
        graph[dst].push_back({src, wgt});
}

ll prims(int src)
{
    int n = graph.size();
    vec<int> parent(n + 1);
    int res = 0;
    unordered_set<int> visited;
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[i] = infp;
    }
    priority_queue<pp, vec<pp>, greater<pp>> pq;
    pq.push({0, src});
    mp[src] = 0;
    while (not pq.empty())
    {
        pp curr = pq.top();
        pq.pop();
        if (visited.count(curr.second))
            continue;
        visited.insert(curr.second);
        res += curr.first;
        for (auto neighbour : graph[curr.second])
        {
            if (not visited.count(neighbour.first) and mp[neighbour.first] > neighbour.second)
            {
                pq.push({neighbour.second, neighbour.first});
                parent[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
            }
        }
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1, list<pp>());
    while (m--)
    {
        int src, dst, wgt;
        cin >> src >> dst >> wgt;
        add(src, dst, wgt);
    }
    int src;
    cin >> src;
    cout << prims(src);
    return 0;
}