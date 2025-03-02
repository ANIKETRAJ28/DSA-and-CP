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
  vector<vector<int>> dp;
  bool match(string &s, string &t, int i, int j)
  {
    int n = s.size();
    return i < n && (s[i] == t[j] || t[j] == '.');
  }

  bool ftd(string &s, string &t, int i, int j)
  {
    int n = s.size();
    int m = t.size();
    // base case
    if (i == n && j == m)
      return true;
    if (j == m)
      return false;
    if (dp[i][j] != -1)
      return dp[i][j];
    bool ans = false;
    if (j + 1 < m && t[j + 1] == '*')
    {
      ans = (match(s, t, i, j) && ftd(s, t, i + 1, j)) || ftd(s, t, i, j + 2);
    }
    else if (match(s, t, i, j))
    {
      ans = ftd(s, t, i + 1, j + 1);
    }
    return dp[i][j] = ans;
  }

  bool isMatch(string s, string p)
  {
    dp.resize(21, vector<int>(21, -1));
    return ftd(s, p, 0, 0);
  }
};

int main()
{

  return 0;
}