#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution
{
public:
  bool palindrome(string s)
  {
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }

  void solve(string &s, vector<string> &ans, vector<vector<string>> &f_ans, int i)
  {
    int n = s.size();
    if (i == n)
    {
      f_ans.push_back(ans);
      return;
    }
    for (int j = i; j < n; j++)
    {
      if (palindrome(s.substr(i, j - i + 1)))
      {
        ans.push_back(s.substr(i, j - i + 1));
        solve(s, ans, f_ans, j + 1);
        ans.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s)
  {
    vector<vector<string>> f_ans;
    vector<string> ans;
    solve(s, ans, f_ans, 0);
    return f_ans;
  }
};

int main()
{

  return 0;
}