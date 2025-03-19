#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/scramble-string/description/

class Solution
{
public:
  unordered_map<string, bool> dp;
  bool ftd(string s1, string s2)
  {
    if (s1 == s2)
      return true;
    if (s1.size() != s2.size())
      return false;
    if (dp.find(s1 + "_" + s2) != dp.end())
      return dp[s1 + "_" + s2];
    int n = s1.size();
    for (int i = 1; i < n; i++)
    {
      bool swap = ftd(s1.substr(0, i), s2.substr(n - i, i)) && ftd(s1.substr(i, n - i), s2.substr(0, n - i));
      bool notSwap = ftd(s1.substr(0, i), s2.substr(0, i)) && ftd(s1.substr(i, n - i), s2.substr(i, n - i));
      if (swap || notSwap)
        return dp[s1 + "_" + s2] = true;
    }
    return dp[s1 + "_" + s2] = false;
  }
  bool isScramble(string s1, string s2)
  {
    return ftd(s1, s2);
  }
};

int main()
{

  return 0;
}