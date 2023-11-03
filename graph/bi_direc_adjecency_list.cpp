#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

int v; // vertices
vec<list<int>> graph;

void add(int src, int dst, bool bi_dir = true)
{
    graph[src].push_back(dst);
    if (bi_dir)
    {
        graph[dst].push_back(src);
    }
}

void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "-> ";
        for (auto el : graph[i])
        {
            cout << el << ", ";
        }
        cout << "\n";
    }
}

int main()
{
    cin >> v;
    int e; // no. of edges
    cin >> e;
    graph.resize(v, list<int>());
    while (e--)
    {
        int src, dst;
        cin >> src >> dst;
        add(src, dst);
    }
    display();
    return 0;
}

// eg
// 7
// 7
// 0 1
// 0 2
// 1 5
// 2 5
// 2 3
// 3 6
// 6 4