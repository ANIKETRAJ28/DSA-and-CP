#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/decode-ways-ii/description/

class Solution
{
public:
#define mod 1000000007
#define ll long long
  int dp[100001];
  int ftd(string &s, int i)
  {
    int n = s.size();
    if (i == n)
      return 1;
    if (s[i] == '0')
      return 0;
    if (dp[i] != -1)
      return dp[i];
    ll ans = 0;
    if (s[i] == '*')
    {
      ans = (ans + 9LL * ftd(s, i + 1)) % mod;
      if (i < n - 1)
      {
        if (s[i + 1] == '*')
        {
          ans = (ans + 9LL * ftd(s, i + 2)) % mod;
          ans = (ans + 6LL * ftd(s, i + 2)) % mod;
        }
        else if (s[i + 1] - '0' <= 6)
        {
          ans = (ans + 2LL * ftd(s, i + 2)) % mod;
        }
        else
        {
          ans = (ans + ftd(s, i + 2)) % mod;
        }
      }
    }
    else
    {
      ans += ftd(s, i + 1);
      if (i < n - 1)
      {
        if (s[i + 1] == '*')
        {
          if (s[i] == '1')
          {
            ans = (ans + 9LL * ftd(s, i + 2)) % mod;
          }
          else if (s[i] == '2')
          {
            ans = (ans + 6LL * ftd(s, i + 2)) % mod;
          }
        }
        else if ((s[i] - '0') * 10 + s[i + 1] - '0' <= 26)
        {
          ans = (ans + ftd(s, i + 2)) % mod;
        }
      }
    }
    return dp[i] = ans;
  }

  int fbu(string &s)
  {
    int n = s.size();
    memset(dp, 0, sizeof(dp));
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
      ll ans = 0;
      if (s[i] == '0')
      {
        dp[i] = 0;
        continue;
      }
      if (s[i] == '*')
      {
        ans = (ans + 9LL * dp[i + 1]) % mod;
        if (i < n - 1)
        {
          if (s[i + 1] == '*')
          {
            ans = (ans + 9LL * dp[i + 2]) % mod;
            ans = (ans + 6LL * dp[i + 2]) % mod;
          }
          else if (s[i + 1] - '0' <= 6)
          {
            ans = (ans + 2LL * dp[i + 2]) % mod;
          }
          else
          {
            ans = (ans + dp[i + 2]) % mod;
          }
        }
      }
      else
      {
        ans += dp[i + 1];
        if (i < n - 1)
        {
          if (s[i + 1] == '*')
          {
            if (s[i] == '1')
            {
              ans = (ans + 9LL * dp[i + 2]) % mod;
            }
            else if (s[i] == '2')
            {
              ans = (ans + 6LL * dp[i + 2]) % mod;
            }
          }
          else if ((s[i] - '0') * 10 + s[i + 1] - '0' <= 26)
          {
            ans = (ans + dp[i + 2]) % mod;
          }
        }
      }
      dp[i] = ans;
    }
    return dp[0];
  }

  int numDecodings(string s)
  {
    // memset(dp, -1, sizeof(dp));
    // return ftd(s, 0);
    return fbu(s);
  }
};

int main()
{

  return 0;
}