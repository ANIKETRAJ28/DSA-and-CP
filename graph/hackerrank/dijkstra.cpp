#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define p pair<int>
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

vec<list<pp>> graph;

void add_edge(int src, int dst, int wgt, bool bi_direc = true)
{
    graph[src].push_back({dst, wgt});
    if (bi_direc)
        graph[dst].push_back({src, wgt});
}

unordered_map<int, int> dijkstra(int src)
{
    int n = graph.size();
    unordered_map<int, int> mp;
    unordered_set<int> visited;
    vec<int> via(n);
    for (int i = 0; i < n; i++)
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
        for (auto neighbor : graph[curr.second])
        {
            if (not visited.count(neighbor.first) and mp[neighbor.first] > mp[curr.second] + neighbor.second)
            {
                pq.push({mp[curr.second] + neighbor.second, neighbor.first});
                mp[neighbor.first] = mp[curr.second] + neighbor.second;
                via[neighbor.first] = curr.second;
            }
        }
    }
    return mp;
}

int main()
{
    int n, m;
    cin >> n >> m;
    graph.resize(n, list<pp>());
    while (m--)
    {
        int src, dst, wgt;
        cin >> src >> dst >> wgt;
        add_edge(src, dst, wgt);
    }
    int src;
    cin >> src;
    unordered_map<int, int> mp = dijkstra(src);
    int dst;
    cin >> dst;
    cout << mp[dst];
    return 0;
}

// eg
// 7
// 9
// 0 1 1
// 0 2 5
// 1 3 1
// 1 2 4
// 2 4 1
// 3 4 1
// 3 6 2
// 4 5 5
// 5 6 1
// 0 5