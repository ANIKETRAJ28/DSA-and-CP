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
    return parent[x] = (x == parent[x]) ? x : find(parent, parent[x]);
}

void Union(vec<int> &parent, vec<int> &size, vec<int> &maxi, vec<int> &mini, int x, int y)
{
    x = find(parent, x);
    y = find(parent, y);
    if (x == y)
        return;
    if (size[x] > size[y])
    {
        size[x] += size[y];
        parent[y] = x;
        maxi[x] = max(maxi[x], maxi[y]);
        mini[x] = min(mini[x], mini[y]);
    }
    else
    {
        size[y] += size[x];
        parent[x] = y;
        maxi[y] = max(maxi[x], maxi[y]);
        mini[y] = min(mini[x], mini[y]);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vec<int> parent(n + 1, 0);
    vec<int> size(n + 1, 1);
    vec<int> maxi(n + 1, 0);
    vec<int> mini(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = maxi[i] = mini[i] = i;
    }
    while (m--)
    {
        string s;
        cin >> s;
        if (s == "union")
        {
            int x, y;
            cin >> x >> y;
            Union(parent, size, maxi, mini, x, y);
        }
        else if (s == "get")
        {
            int x;
            cin >> x;
            x = find(parent, x);
            cout << mini[x] << " " << maxi[x] << " " << size[x] << "\n";
        }
    }
    return 0;
}

// 5 11
// union 1 2
// get 3
// get 2
// union 2 3
// get 2
// union 1 3
// get 5
// union 4 5
// get 5
// union 4 1
// get 5

// 5 11
// 3 3 1
// 1 2 2
// 5 5 1
// 4 5 2
// 1 5 5