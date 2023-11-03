#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

int find(vec<int> &parent, int x)
{
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

void Union(vec<int> &parent, vec<int> &rank, int x, int y)
{
    x = find(parent, x);
    y = find(parent, y);

    if (rank[x] >= rank[y])
    {
        rank[x]++;
        parent[y] = x;
    }
    else
    {
        rank[y]++;
        parent[x] = y;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vec<int> parent(n + 1);
    vec<int> rank(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
    while (m--)
    {
        string s;
        cin >> s;
        if (s == "union")
        {
            int x, y;
            cin >> x >> y;
            Union(parent, rank, x, y);
        }
        else if (s == "find")
        {
            int x;
            cin >> x;
            cout << find(parent, x);
        }
    }
    return 0;
}