#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

class Solution
{
public:
  vector<int> findAnagrams(string s2, string s1)
  {
    int n1 = s1.size();
    int n2 = s2.size();
    if (n1 > n2)
      return {};
    unordered_map<char, int> mp1, mp2;
    vector<int> ans;
    for (int i = 0; i < n1; i++)
      mp1[s1[i]]++;
    int need = mp1.size();
    int have = 0;
    int i = 0, j = 0;
    for (i; i < n1; i++)
    {
      if (mp1.find(s2[i]) != mp1.end())
      {
        mp2[s2[i]]++;
        if (mp1[s2[i]] == mp2[s2[i]])
          have++;
      }
    }
    if (have == need)
      ans.push_back(j);
    while (i < n2)
    {
      if (mp1.find(s2[j]) != mp1.end())
      {
        if (mp2[s2[j]] == mp1[s2[j]])
          have--;
        mp2[s2[j]]--;
      }
      if (mp1.find(s2[i]) != mp1.end())
      {
        mp2[s2[i]]++;
        if (mp2[s2[i]] == mp1[s2[i]])
          have++;
      }
      j++;
      i++;
      if (have == need)
        ans.push_back(j);
    }
    return ans;
  }
};

int main()
{

  return 0;
}