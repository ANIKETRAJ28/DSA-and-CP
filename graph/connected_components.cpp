#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

int v;
vec<list<int>> graph;
unordered_set<int> visited;

void add(int src, int dst, bool bi_direc = true)
{
    graph[src].push_back(dst);
    if (bi_direc)
        graph[dst].push_back(src);
}

void dfs(int src)
{
    visited.insert(src);
    for (auto ele : graph[src])
    {
        if (not visited.count(ele))
        {
            dfs(ele);
        }
    }
}

int main()
{
    cin >> v;
    graph.resize(v, list<int>());
    int e;
    cin >> e;
    while (e--)
    {
        int src, dst;
        cin >> src >> dst;
        add(src, dst);
    }
    int res = 0;
    for (int i = 0; i < v; i++)
    {
        if (visited.count(i) == 0)
        {
            res++;
            dfs(i);
        }
    }
    cout << res;
    return 0;
}