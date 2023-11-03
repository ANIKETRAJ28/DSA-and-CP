#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

int find(vec<int> &parent, int a)
{
    return parent[a] = (a == parent[a]) ? a : find(parent, parent[a]);
}

bool Union(vec<int> &parent, vec<int> &rank, int a, int b)
{
    a = find(parent, a);
    b = find(parent, b);
    if (a == b)
        return true;
    if (rank[a] >= rank[b])
    {
        rank[a]++;
        parent[b] = a;
    }
    else
    {
        rank[b]++;
        parent[a] = b;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vec<int> parent(n + 1, 0);
    vec<int> rank(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (Union(parent, rank, a, b))
        {
            cout << "Cycle detected\n";
        }
    }
    return 0;
}

// eg
// 10
// 10
// 0 1
// 0 2
// 0 3
// 3 4
// 4 5
// 5 6
// 3 6
// 6 7
// 7 8
// 8 9