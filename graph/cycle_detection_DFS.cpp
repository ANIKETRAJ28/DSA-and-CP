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
unordered_set<int> visited;

void add(int src, int dst, bool bi_direct = true)
{
    graph[src].push_back(dst);
    if (bi_direct)
    {
        graph[dst].push_back(src);
    }
}

void display()
{
    for (int i = 0; i < v; i++)
    {
        cout << i << " -> ";
        for (auto neighbor : graph[i])
        {
            cout << neighbor << ", ";
        }
        cout << "\n";
    }
}

bool dfs(int src, int parent)
{
    visited.insert(src);
    for (auto neighbor : graph[src])
    {
        if (visited.count(neighbor) and neighbor != parent)
        {
            // cycle found
            return true;
        }
        if (!visited.count(neighbor))
        {
            return dfs(neighbor, src);
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
    display();
    bool flag = false;
    for (int i = 0; i < v; i++)
    {
        if (not visited.count(i))
        {
            flag = dfs(i, -1);
            if (flag)
                cout << "Cycle detected\n";
            return 0;
        }
    }

    return 0;
}