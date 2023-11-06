#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

int main()
{
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    vec<vec<char>> grid(n, vec<char>(m, '.'));
    for (int i = 0; i < n; i++)
    {
        if (cnt % 2 == 0 and i % 2 != 0)
        {
            grid[i][m - 1] = '#';
            cnt++;
        }
        else if (cnt % 2 != 0 and i % 2 != 0)
        {
            grid[i][0] = '#';
            cnt++;
        }
        for (int j = 0; j < m; j++)
        {
            if (i % 2 == 0)
                grid[i][j] = '#';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    return 0;
}