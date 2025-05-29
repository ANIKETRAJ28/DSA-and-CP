#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/get-equal-substrings-within-budget/description/

class Solution
{
public:
  int equalSubstring(string s, string t, int maxCost)
  {
    int n = s.size();
    int ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
      ans = max(ans, i - j);
      while (j <= i && maxCost < abs(s[i] - t[i]))
      {
        maxCost += abs(s[j] - t[j]);
        j++;
      }
      maxCost -= abs(s[i] - t[i]);
    }
    ans = max(ans, n - j);
    return ans;
  }
};

int main()
{

  return 0;
}