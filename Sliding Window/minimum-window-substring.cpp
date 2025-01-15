#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-window-substring/

class Solution
{
public:
  string minWindow(string s, string t)
  {
    int n = s.size();
    int m = t.size();
    if (m > n)
      return "";
    unordered_map<char, int> mp1, mp2;
    for (int i = 0; i < m; i++)
      mp2[t[i]]++;
    int have = 0, need = mp2.size();
    int i = 0, j = 0;
    string ans = "";
    int strt = -1, minLen = INT_MAX;
    while (j < n)
    {
      if (mp2.find(s[j]) != mp2.end())
      {
        mp1[s[j]]++;
        if (mp1[s[j]] == mp2[s[j]])
          have++;
      }
      while (i <= j && have == need)
      {
        if (j - i + 1 < minLen)
        {
          strt = i;
          minLen = j - i + 1;
        }
        if (mp2.find(s[i]) != mp2.end())
        {
          mp1[s[i]]--;
          if (mp1[s[i]] < mp2[s[i]])
            have--;
        }
        i++;
      }
      j++;
    }
    return strt == -1 ? ans : s.substr(strt, minLen);
  }
};

int main()
{

  return 0;
}