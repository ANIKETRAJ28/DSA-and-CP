#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/extra-characters-in-a-string/

class Solution
{
public:
  unordered_set<string> st;
  vector<int> dp;
  int ftd(string &s, int i)
  {
    int n = s.size();
    if (i == n)
      return 0;
    if (dp[i] != -1)
      return dp[i];
    int ans = INT_MAX;
    for (int k = i; k < n; k++)
    {
      if (st.find(s.substr(i, k - i + 1)) != st.end())
      {
        ans = min(ans, ftd(s, k + 1));
      }
    }
    ans = min(ans, 1 + ftd(s, i + 1));
    return dp[i] = ans;
  }

  int fbu(string &s)
  {
    int n = s.size();
    dp.resize(51, INT_MAX);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      int ans = INT_MAX;
      for (int k = i; k < n; k++)
      {
        if (st.find(s.substr(i, k - i + 1)) != st.end())
        {
          ans = min(ans, dp[k + 1]);
        }
      }
      ans = min(ans, 1 + dp[i + 1]);
      dp[i] = ans;
    }
    return dp[0];
  }

  int minExtraChar(string s, vector<string> &dictionary)
  {
    int n = dictionary.size();
    // dp.resize(51, -1);
    for (int i = 0; i < n; i++)
    {
      st.insert(dictionary[i]);
    }
    // return ftd(s, 0);
    return fbu(s);
  }
};

int main()
{

  return 0;
}