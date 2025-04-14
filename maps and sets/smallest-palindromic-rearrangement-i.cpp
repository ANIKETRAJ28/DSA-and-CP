#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/smallest-palindromic-rearrangement-i/description/

class Solution
{
public:
  string smallestPalindrome(string s)
  {
    int n = s.size();
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
      mp[s[i]]++;
    }
    int i = 0, j = n - 1;
    while (!mp.empty())
    {
      auto ele = mp.begin();
      char ch = ele->first;
      int freq = ele->second;
      mp.erase(ch);
      while (freq)
      {
        if (freq % 2)
        {
          s[n / 2] = ch;
          freq--;
        }
        else
        {
          s[i] = ch;
          s[j] = ch;
          freq -= 2;
          i++;
          j--;
        }
      }
    }
    return s;
  }
};

int main()
{

  return 0;
}