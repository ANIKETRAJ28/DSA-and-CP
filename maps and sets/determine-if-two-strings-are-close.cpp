#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/determine-if-two-strings-are-close/

class Solution
{
public:
  bool closeStrings(string word1, string word2)
  {
    int n1 = word1.size();
    int n2 = word2.size();
    unordered_map<char, int> mp1, mp2;
    for (int i = 0; i < n1; i++)
    {
      mp1[word1[i]]++;
    }
    for (int i = 0; i < n2; i++)
    {
      mp2[word2[i]]++;
    }
    if (mp1.size() != mp2.size())
      return false;
    for (auto it : mp1)
    {
      if (mp2.find(it.first) == mp2.end())
        return false;
    }
    for (auto it : mp2)
    {
      if (mp1.find(it.first) == mp1.end())
        return false;
    }
    vector<int> freq1, freq2;
    for (auto it : mp1)
    {
      freq1.push_back(it.second);
    }
    for (auto it : mp2)
    {
      freq2.push_back(it.second);
    }
    sort(freq1.begin(), freq1.end());
    sort(freq2.begin(), freq2.end());
    return freq1 == freq2;
  }
};

int main()
{

  return 0;
}