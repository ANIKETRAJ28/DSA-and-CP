#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

class Solution
{
public:
  vector<int> dp;
  bool isPalindrome(string &s, int i, int j)
  {
    while (i < j)
    {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }
  int ftd(string &s, int i)
  {
    int n = s.size();
    if (i == n)
      return 0;
    if (dp[i] != -1)
      return dp[i];
    int ans = INT_MAX;
    for (int j = i; j < n; j++)
    {
      if (isPalindrome(s, i, j))
      {
        if (j != n - 1)
          ans = min(ans, 1 + ftd(s, j + 1));
        else
          ans = min(ans, ftd(s, j + 1));
      }
    }
    return dp[i] = ans;
  }

  int fbu(string &s)
  {
    int n = s.size();
    dp.resize(2001, INT_MAX);
    // base case
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = i; j < n; j++)
      {
        if (isPalindrome(s, i, j))
        {
          if (j == n - 1)
          {
            dp[i] = min(dp[i], dp[j + 1]);
          }
          else
            dp[i] = min(dp[i], 1 + dp[j + 1]);
        }
      }
    }
    return dp[0];
  }

  int minCut(string s)
  {
    // dp.resize(2001, -1);
    // return ftd(s, 0);
    return fbu(s);
  }
};

int main()
{

  return 0;
}