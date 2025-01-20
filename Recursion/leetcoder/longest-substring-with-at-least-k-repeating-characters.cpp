#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/

class Solution
{
public:
  int longestSubstring(string s, int k)
  {
    int n = s.size();
    if (n < k)
      return 0;
    if (k == 1)
      return n;
    unordered_map<char, int> mp;
    for (char c : s)
      mp[c]++;
    int i = 0;
    while (i < n && mp[s[i]] >= k)
      i++;
    if (i == n)
      return n;
    int l1 = longestSubstring(s.substr(0, i), k);
    while (i < n && mp[s[i]] < k)
      i++;
    if (i == n)
      return l1;
    int l2 = longestSubstring(s.substr(i), k);
    return max(l1, l2);
  }
};

int main()
{

  return 0;
}