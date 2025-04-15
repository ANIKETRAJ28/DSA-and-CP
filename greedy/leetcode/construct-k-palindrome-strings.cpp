#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/construct-k-palindrome-strings/description/

class Solution
{
public:
  bool canConstruct(string s, int k)
  {
    int n = s.size();
    if (k > n)
      return false;
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
      mp[s[i]]++;
    }
    int ods = 0;
    for (auto el : mp)
    {
      ods += el.second % 2;
    }
    return ods <= k;
  }
};

int main()
{

  return 0;
}