#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

vec<vec<int>> dp;

int ftd(vec<vec<int>> &v, int i, int j)
{
    int n = v.size();
    if (i == n - 1)
        return v[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    for (int k = 0; k < 3; k++)
    {
        if (k != j)
        {
            ans = max(ans, ftd(v, i + 1, k));
        }
    }
    ans += v[i][j];
    return dp[i][j] = ans;
}

int main()
{
    int n;
    cin >> n;
    vec<vec<int>> v(n, vec<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    dp.resize(n + 1, vec<int>(3, -1));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans = max(ans, ftd(v, i, j));
        }
    }
    cout << ans;
    return 0;
}