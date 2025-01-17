#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution
{
public:
  bool checkSubstring(unordered_map<string, int> mp, string s, int wordLen)
  {
    for (int j = 0; j < s.size(); j += wordLen)
    {
      string w = s.substr(j, wordLen);
      if (mp.find(w) != mp.end())
      {
        if (--mp[w] == -1)
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
    return true;
  }

  vector<int> findSubstring(string s, vector<string> &words)
  {
    int n = s.size();
    int m = words.size();
    int wordSize = words[0].size();
    int windowSize = wordSize * m;
    unordered_map<string, int> mp;
    vector<int> ans;

    for (int i = 0; i < m; i++)
      mp[words[i]]++;

    for (int i = 0; i + windowSize <= n; i++)
    {
      if (checkSubstring(mp, s.substr(i, windowSize), wordSize))
        ans.push_back(i);
    }
    return ans;
  }
};

int main()
{

  return 0;
}