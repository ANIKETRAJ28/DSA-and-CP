#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

vector<vector<ll>> dp;

ll ftd(vector<int> &wgt, vector<int> &val, int v, int i)
{
  int n = wgt.size();
  if (v == 0)
    return 0;
  if (i == n)
    return infp;
  if (dp[i][v] != -1)
    return dp[i][v];
  // not pick
  ll ans = ftd(wgt, val, v, i + 1);
  // pcik
  if (val[i] <= v)
    ans = min(ans, wgt[i] + ftd(wgt, val, v - val[i], i + 1));
  return dp[i][v] = ans;
}

ll fbu(vector<int> &wgt, vector<int> &val, int w)
{
  int n = wgt.size();
  ll f_ans = 0;
  for (int i = 0; i <= n; i++)
    dp[i][0] = 0;
  for (int v = 0; v <= n * 1000; v++)
  {
    for (int i = n - 1; i >= 0; i--)
    {
      // not pick
      ll ans = dp[i + 1][v];
      // pick
      if (val[i] <= v)
        ans = min(ans, wgt[i] + dp[i + 1][v - val[i]]);
      dp[i][v] = ans;
      if (ans <= w)
        f_ans = v;
    }
  }
  return f_ans;
}

int main()
{
  int n, w;
  cin >> n >> w;
  vector<int> wgt(n), val(n);
  for (int i = 0; i < n; i++)
  {
    cin >> wgt[i] >> val[i];
  }
  // dp.resize(105, vector<ll>(100005, -1));
  // ll f_ans = 0;
  // for (int i = 0; i <= n * 1000; i++)
  // {
  //   ll ans = ftd(wgt, val, i, 0);
  //   if (ans <= w)
  //     f_ans = i;
  // }
  // cout << f_ans;

  dp.resize(105, vector<ll>(100005, INT_MAX));
  cout << fbu(wgt, val, w);
  return 0;
}