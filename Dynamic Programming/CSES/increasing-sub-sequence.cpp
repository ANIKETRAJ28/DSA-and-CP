#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://cses.fi/problemset/task/1145

vec<ll> dp;

ll ftd(vec<int> &v, int i)
{
    // base case
    if (i == 0)
        return 1;
    if (dp[i] != -1)
        return dp[i];
    ll ans = infn;
    for (int j = 0; j < i; j++)
    {
        if (v[j] < v[i])
            ans = max(ans, ftd(v, j));
    }
    if (ans == infn)
        return dp[i] = 1;
    return dp[i] = 1 + ans;
}

int main()
{
    int n;
    cin >> n;
    vec<int> v(n);
    dp.resize(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll ans = infn;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, ftd(v, i));
    }
    cout << ans;
    return 0;
}