#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/wildcard-matching/

class Solution
{
public:
  // vector<vector<int>> dp;

  bool match(string &s, string &t, int i, int j)
  {
    return s[i] == t[j] || t[j] == '?';
  }

  // bool ftd(string &s, string &t, int i, int j) {
  //     int n = s.size();
  //     int m = t.size();
  //     if(i == n && j == m) return true;
  //     if(j == m) return false;
  //     if(i == n) {
  //         while(j < m && t[j] == '*') j++;
  //         return j >= m;
  //     }
  //     if(dp[i][j] != -1) return dp[i][j];
  //     bool ans = false;
  //     if(t[j] == '*') {
  //         ans = ftd(s, t, i, j+1) || ftd(s, t, i+1, j);
  //     } else if(match(s, t, i, j)) {
  //         ans = ftd(s, t, i+1, j+1);
  //     }
  //     return dp[i][j] = ans;
  // }

  bool fbu(string &s, string &t)
  {
    int n = s.size();
    int m = t.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));
    dp[n][m] = true;
    for (int j = m - 1; j >= 0; j--)
    {
      if (t[j] == '*')
        dp[n][j] = dp[n][j + 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = m - 1; j >= 0; j--)
      {
        bool ans = false;
        if (t[j] == '*')
        {
          ans = dp[i + 1][j] || dp[i][j + 1];
        }
        else if (match(s, t, i, j))
        {
          ans = dp[i + 1][j + 1];
        }
        dp[i][j] = ans;
      }
    }
    return dp[0][0];
  }

  bool isMatch(string s, string p)
  {
    // dp.resize(s.size()+1, vector<int> (p.size()+1, -1));
    // return ftd(s, p, 0, 0);
    return fbu(s, p);
  }
};

int main()
{

  return 0;
}