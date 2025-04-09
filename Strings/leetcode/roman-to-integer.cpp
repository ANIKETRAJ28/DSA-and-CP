#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/roman-to-integer/description/

class Solution
{
public:
  int romanToInt(string s)
  {
    int n = s.size();
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    char prv = '*';
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      if (prv == '*')
      {
        ans += mp[s[i]];
      }
      else if (mp[s[i]] < mp[prv])
      {
        ans -= mp[s[i]];
      }
      else
        ans += mp[s[i]];
      prv = s[i];
    }
    return ans;
  }
};

int main()
{

  return 0;
}