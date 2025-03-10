#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/palindrome-partitioning-iii/

class Solution
{
public:
  vector<vector<int>> dp;
  int minChanges(string &s, int i, int j)
  {
    int cnt = 0;
    while (i < j)
    {
      if (s[i] != s[j])
        cnt++;
      i++;
      j--;
    }
    return cnt;
  }

  int ftd(string &s, int i, int cnt)
  {
    int n = s.size();
    if (i == n && cnt == 0)
      return 0;
    if (i == n || cnt == 0)
      return INT_MAX;
    if (dp[i][cnt] != -1)
      return dp[i][cnt];
    int ans = INT_MAX;
    for (int j = i; j < n; j++)
    {
      int res = ftd(s, j + 1, cnt - 1);
      if (res != INT_MAX)
        ans = min(ans, res + minChanges(s, i, j));
    }
    return dp[i][cnt] = ans;
  }

  int fbu(string &s, int cnt)
  {
    int n = s.size();
    dp.resize(n + 1, vector<int>(cnt + 1, INT_MAX));
    dp[n][0] = 0;
    for (int k = 1; k <= cnt; k++)
    {
      for (int i = n - 1; i >= 0; i--)
      {
        for (int j = i; j < n; j++)
        {
          int cuts = minChanges(s, i, j);
          int res = dp[j + 1][k - 1];
          if (res != INT_MAX)
            dp[i][k] = min(dp[i][k], res + cuts);
        }
      }
    }
    return dp[0][cnt];
  }

  int palindromePartition(string s, int k)
  {
    dp.resize(105, vector<int>(105, -1));
    return ftd(s, 0, k);
  }
};

int main()
{

  return 0;
}