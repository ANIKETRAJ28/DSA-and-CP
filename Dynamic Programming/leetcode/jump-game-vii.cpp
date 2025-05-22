#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/jump-game-vii/description/

class Solution
{
public:
  bool canReach(string s, int minJump, int maxJump)
  {
    int n = s.size();
    if (s[n - 1] == '1')
      return false;
    vector<bool> dp(n, 0);
    dp[0] = 1;
    int strt = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
      if (!dp[i])
        continue;
      strt = max(end + 1, i + minJump);
      end = min(n - 1, i + maxJump);
      for (int j = strt; j <= end; j++)
      {
        if (s[j] == '1')
          continue;
        dp[j] = 1;
      }
      if (dp[n - 1] == 1)
        return true;
    }
    return dp[n - 1];
  }
};

int main()
{

  return 0;
}