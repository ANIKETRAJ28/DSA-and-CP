#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/generate-parentheses/description/

class Solution
{
public:
  vector<string> ans;
  void generate(string &s, int n, int o, int c)
  {
    if (o == n && c == n)
    {
      ans.push_back(s);
      return;
    }
    // opening
    if (o != n)
    {
      s += '(';
      generate(s, n, o + 1, c);
      s.pop_back();
    }
    // closing
    if (o <= n && c < o)
    {
      s += ')';
      generate(s, n, o, c + 1);
      s.pop_back();
    }
  }
  vector<string> generateParenthesis(int n)
  {
    string s = "";
    generate(s, n, 0, 0);
    return ans;
  }
};

int main()
{

  return 0;
}