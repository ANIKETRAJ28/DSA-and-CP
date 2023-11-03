#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

int v;
vec<unordered_set<int>> graph;

void add(int src, int dst, bool bi_direc = true)
{
    graph[src].insert(dst);
    if (bi_direc)
    {
        graph[dst].insert(src);
    }
}

void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " ->";
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
    graph.resize(v, unordered_set<int>());
    int e;
    cin >> e;
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
// 1 0
// 5 2
// 3 2
// 6 3
// 6 4
// 0 2