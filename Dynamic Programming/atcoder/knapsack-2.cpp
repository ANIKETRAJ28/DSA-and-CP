#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://atcoder.jp/contests/dp/tasks/dp_e

vec<vec<ll>> dp;

ll ftd(vec<int> &wts, vec<int> &val, int idx, int tv)
{
    int n = wts.size();
    if (dp[idx][tv] != -1)
        return dp[idx][tv];
    if (tv == 0)
        return 0;
    if (idx == n)
        return infp;
    ll ans = infp;
    // not-pick
    ans = min(ans, ftd(wts, val, idx + 1, tv));
    // pick
    if (val[idx] <= tv)
    {
        ans = min(ans, wts[idx] + ftd(wts, val, idx + 1, tv - val[idx]));
    }
    return dp[idx][tv] = ans;
}

ll fbu(vec<int> &wts, vec<int> &val, int tv, int wt)
{
    // base case handled
    dp.resize(105, vec<ll>(100005, infp));
    int n = wts.size();
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i][0] = 0;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= tv; j++)
        {
            ll ans = infp;
            // not-pick
            ans = dp[i + 1][j];
            // pick
            if (val[i] <= j)
            {
                ans = min(ans, wts[i] + dp[i + 1][j - val[i]]);
            }
            dp[i][j] = ans;
        }
    }
    int ans = -1;
    for (int i = 0; i <= tv; i++)
    {
        if (dp[0][i] <= wt)
            ans = i;
    }
    return ans;
}

int main()
{
    int n, w;
    cin >> n >> w;
    vec<int> wts(n);
    vec<int> val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wts[i] >> val[i];
    }
    dp.resize(105, vec<ll>(100005, -1));
    int ans = -1;
    for (int i = 0; i <= n * 1000; i++)
    {
        if (ftd(wts, val, 0, i) <= w)
            ans = i;
    }
    cout << ans;
    // cout<<fbu(wts, val, n*1000, w);
    return 0;
}