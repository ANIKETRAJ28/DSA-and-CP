#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/word-break/description/

class Solution
{
public:
  unordered_set<string> st;
  int dp[301];
  bool ftd(string &s, int i)
  {
    int n = s.size();
    if (i == n)
      return true;
    if (dp[i] != -1)
      return dp[i];
    for (int idx = i; idx < n; idx++)
    {
      string str = s.substr(i, idx - i + 1);
      if (st.find(str) != st.end() && ftd(s, idx + 1))
        return dp[i] = true;
    }
    return dp[i] = false;
  }

  bool fbu(string &s)
  {
    int n = s.size();
    memset(dp, 0, sizeof(dp));
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
      bool ans = false;
      for (int j = i; j < n; j++)
      {
        string str = s.substr(i, j - i + 1);
        if (st.find(str) != st.end() && dp[j + 1])
        {
          ans = true;
          break;
        }
      }
      dp[i] = ans;
    }
    return dp[0];
  }

  bool wordBreak(string s, vector<string> &wordDict)
  {
    int n = wordDict.size();
    // memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
      st.insert(wordDict[i]);
    // return ftd(s, 0);
    return fbu(s);
  }
};

int main()
{

  return 0;
}