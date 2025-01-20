#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/

class Solution
{
public:
  int maximumLength(string s)
  {
    int n = s.size();
    vector<vector<int>> mp(26, vector<int>(n + 1, 0));
    char prvChar = s[0];
    mp[s[0] - 'a'][1] = 1;
    int ans = -1;
    int len = 1;
    for (int i = 1; i < n; i++)
    {
      if (prvChar != s[i])
      {
        len = 1;
        prvChar = s[i];
        mp[prvChar - 'a'][len] += 1;
      }
      else
      {
        len++;
        mp[prvChar - 'a'][len] += 1;
      }
    }
    for (int i = 0; i < 26; i++)
    {
      int sz = 0;
      for (int j = n; j >= 1; j--)
      {
        sz += mp[i][j];
        if (sz >= 3)
        {
          ans = max(ans, j);
          break;
        }
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}