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

void add(int src, int dst, bool bi_direc = true)
{
    graph[src].push_back(dst);
    if (bi_direc)
    {
        graph[dst].push_back(src);
    }
}

void topologicalSortBFS()
{
    // kahn's algo
    vec<int> indegree(v, 0);
    unordered_set<int> visited;
    for (int i = 0; i < v; i++)
    {
        for (auto ele : graph[i])
        {
            // i ---> neigbour edge
            indegree[ele]++;
        }
    }
    queue<int> qu;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            qu.push(i);
            visited.insert(i);
        }
    }

    while (not qu.empty())
    {
        int el = qu.front();
        qu.pop();
        cout << el << " ";
        for (auto neighbor : graph[el])
        {
            if (not visited.count(neighbor))
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                {
                    qu.push(neighbor);
                    visited.insert(neighbor);
                }
            }
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
        add(src, dst, false);
    }
    topologicalSortBFS();
    return 0;
}

// 7
// 11
// 0 2
// 1 2
// 2 3
// 2 4
// 1 3
// 3 5
// 5 6
// 4 6
// 2 6
// 2 5
// 6 7