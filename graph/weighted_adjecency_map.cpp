#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

int v;
vec<unordered_map<int, int>> graph;

void add(int src, int dst, int wt, bool bi_direc = true)
{
    graph[src][dst] = wt;
    if (bi_direc)
    {
        graph[dst][src] = wt;
    }
}

void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (auto el : graph[i])
        {
            cout << "(" << el.first << ", " << el.second << "),";
        }
        cout << "\n";
    }
}

int main()
{
    cin >> v;
    graph.resize(v, unordered_map<int, int>());
    int e;
    cin >> e;
    while (e--)
    {
        int src, dst, wt;
        cin >> src >> dst >> wt;
        add(src, dst, wt);
    }
    display();
    return 0;
}
// eg
// 7
// 7
// 0 2 5
// 1 0 1
// 5 1 2
// 5 2 3
// 3 2 6
// 6 3 8
// 6 4 9