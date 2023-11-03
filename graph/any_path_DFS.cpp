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
    {
        graph[dst].push_back(src);
    }
}

bool anyPath(int src, int dst)
{
    if (src == dst)
        return true;
    visited.insert(src);
    for (auto neighbour : graph[src])
    {
        if (visited.count(neighbour) == 0)
        {
            if (anyPath(neighbour, dst))
                return true;
        }
    }
    return false;
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
    int x, y;
    cin >> x >> y;
    cout << anyPath(x, y);
    return 0;
}
// eg. input
// 7
// 8
// 0 1
// 0 4
// 1 3
// 4 3
// 1 5
// 5 6
// 6 2
// 5 2
// 0 6