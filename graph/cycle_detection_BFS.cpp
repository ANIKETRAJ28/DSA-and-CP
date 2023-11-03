#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

vec<list<int>> graph;
int v;
vec<int> parent;

void add(int src, int dst, bool bi_direc = true)
{
    graph[src].push_back(dst);
    if (bi_direc)
    {
        graph[dst].push_back(src);
    }
}

void display()
{
    for (int i = 0; i < v; i++)
    {
        cout << i << " -> ";
        for (auto ele : graph[i])
        {
            cout << ele << ", ";
        }
        cout << "\n";
    }
}

bool bfs(int src)
{
    unordered_set<int> visited;
    queue<int> qu;
    qu.push(src);
    visited.insert(src);
    parent[src] = -1;
    while (not qu.empty())
    {
        int ele = qu.front();
        qu.pop();
        for (auto neighbor : graph[ele])
        {
            if (not visited.count(neighbor))
            {
                qu.push(neighbor);
                parent[neighbor] = ele;
                visited.insert(neighbor);
            }
            else
            {
                if (parent[ele] != neighbor)
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    cin >> v;
    graph.resize(v, list<int>());
    parent.resize(v);
    int e;
    cin >> e;
    while (e--)
    {
        int src, dst;
        cin >> src >> dst;
        add(src, dst);
    }
    display();
    for (int i = 0; i < v; i++)
    {
        if (not bfs(i))
        {
            cout << "Cycle found\n";
            return 0;
        }
    }
    return 0;
}