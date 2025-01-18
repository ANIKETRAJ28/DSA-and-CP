#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution
{
public:
  int numberOfSubstrings(string s)
  {
    int n = s.size();
    unordered_map<char, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == 'a' || s[i] == 'b' || s[i] == 'c')
        mp[s[i]] = i;
      if (mp.size() == 3)
      {
        int minLen = INT_MAX;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
          minLen = min(minLen, it->second);
        }
        cnt += i + 1 - (i - minLen + 1) + 1;
      }
    }
    return cnt;
  }
};

int main()
{

  return 0;
}