#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://cses.fi/problemset/task/1140

vec<vec<ll>> dp;

ll ftd(vec<ll> &strt, vec<ll> &end, vec<ll> &price, ll i, ll srt)
{
    int n = strt.size();
    if (i == n)
        return 0;
    // if (dp[i][srt] != -1)
    //     return dp[i][srt];
    ll ans = 0;
    // not pick
    ans = ftd(strt, end, price, i + 1, srt);
    // pick
    if (strt[i] > srt)
        ans = max(ans, price[i] + ftd(strt, end, price, i + 1, end[i]));
    return /*dp[i][srt] =*/ans;
}

int main()
{
    int n;
    cin >> n;
    vec<ll> strt(n), end(n), price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strt[i] >> end[i] >> price[i];
    }
    // dp.clear();
    // dp.resize(n, vec<ll>(infp, -1));
    cout << ftd(strt, end, price, 0, 0);
    return 0;
}