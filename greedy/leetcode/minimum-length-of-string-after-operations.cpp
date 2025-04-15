#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-length-of-string-after-operations/description/

class Solution
{
public:
  int minimumLength(string s)
  {
    int n = s.size();
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
      mp[s[i]]++;
    }
    int ans = 0;
    for (auto el : mp)
    {
      ans += el.second % 2;
      if (el.second % 2 == 0)
        ans += 2;
    }
    return ans;
  }
};

int main()
{

  return 0;
}