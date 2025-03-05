#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/

class Solution
{
public:
  vector<vector<int>> dp;

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

  int ftd(string &s, int i, int k)
  {
    int n = s.size();
    if (i == n)
      return 0;
    if (dp[i][k] != -1)
      return dp[i][k];
    int ans = ftd(s, i + 1, k);
    for (int j = i + k - 1; j < n; j++)
    {
      if (isPalindrome(s, i, j))
      {
        ans = max(ans, 1 + ftd(s, j + 1, k));
      }
    }
    return dp[i][k] = ans;
  }

  int fbu(string &s, int k)
  {
    int n = s.size();
    for (int i = n - k; i >= 0; i--)
    {
      int ans = dp[i + 1][k];
      for (int j = i + k - 1; j < n; j++)
      {
        if (isPalindrome(s, i, j))
        {
          ans = max(ans, 1 + dp[j + 1][k]);
        }
      }
      dp[i][k] = ans;
    }
    return dp[0][k];
  }

  int maxPalindromes(string s, int k)
  {
    int n = s.size();
    // dp.resize(n+1, vector<int> (k+1, -1));
    // return ftd(s, 0, k);
    dp.resize(n + 1, vector<int>(k + 1, 0));
    return fbu(s, k);
  }
};

int main()
{

  return 0;
}