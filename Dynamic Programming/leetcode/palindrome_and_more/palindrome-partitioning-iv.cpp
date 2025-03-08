#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/palindrome-partitioning-iv/

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
  bool ftd(string &s, int i, int cnt)
  {
    int n = s.size();
    if (i == n && cnt == 0)
      return 1;
    if (i == n || cnt == 0)
      return 0;
    if (dp[i][cnt] != -1)
      return dp[i][cnt];
    bool ans = false;
    for (int j = i; j < n; j++)
    {
      if (isPalindrome(s, i, j))
      {
        ans = ans || ftd(s, j + 1, cnt - 1);
        if (ans)
          return dp[i][cnt] = ans;
      }
    }
    return dp[i][cnt] = ans;
  }

  bool checkPartitioning(string s)
  {
    dp.resize(2001, vector<int>(4, -1));
    return ftd(s, 0, 3);
  }
};

int main()
{

  return 0;
}