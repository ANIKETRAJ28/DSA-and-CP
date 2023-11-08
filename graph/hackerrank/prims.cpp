#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

vec<list<pp>> graph;

void add_edge(int src, int dst, int wgt, bool bi_direc = true)
{
    graph[src].push_back({wgt, dst});
    if (bi_direc)
        graph[dst].push_back({wgt, src});
}

ll prims(int src, int n)
{
    vec<int> parent(n + 1);
    priority_queue<pp, vec<pp>, greater<pp>> pq;
    unordered_set<int> visited;
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[i] = infp;
    }
    pq.push({0, src});
    mp[src] = 0;
    int cnt = 0; // n-1 edges
    int res = 0; // total weights
    while (cnt < n and not pq.empty())
    {
        pp curr = pq.top();
        pq.pop();
        if (visited.count(curr.second))
            continue;
        visited.insert(curr.second);
        cnt++;
        res += curr.first;

        for (auto neighbour : graph[curr.second])
        {
            if (not visited.count(neighbour.second) and mp[neighbour.second] > neighbour.first)
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
        add_edge(src, dst, wgt);
    }
    int src;
    cin >> src;
    cout << prims(src, n) << "\n";
    return 0;
}