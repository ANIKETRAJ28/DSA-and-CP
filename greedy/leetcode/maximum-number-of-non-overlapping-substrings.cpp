#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/

class Solution
{
public:
  static bool cmp(pair<int, int> &p1, pair<int, int> &p2)
  {
    return p1.second < p2.second;
  }
  vector<string> maxNumOfSubstrings(string s)
  {
    int n = s.size();
    vector<string> ans;
    vector<pair<int, int>> intervals;
    unordered_map<char, pair<int, int>> mp;
    for (int i = 0; i < n; i++)
    {
      if (mp.find(s[i]) == mp.end())
      {
        mp[s[i]] = {i, i};
      }
      else
      {
        mp[s[i]].second = i;
      }
    }
    for (int i = 0; i < s.size(); i++)
    {
      int strt = mp[s[i]].first;
      if (strt != i)
        continue;
      int end = mp[s[i]].second;
      for (int j = strt; j < end; j++)
      {
        if (mp[s[j]].first < strt)
        {
          end = -1;
          break;
        }
        else
        {
          end = max(end, mp[s[j]].second);
        }
      }
      if (end >= strt)
      {
        intervals.push_back({strt, end});
      }
    }
    sort(intervals.begin(), intervals.end(), cmp);
    int end = -1;
    for (int i = 0; i < intervals.size(); i++)
    {
      if (intervals[i].first > end)
      {
        ans.push_back(s.substr(intervals[i].first, intervals[i].second - intervals[i].first + 1));
        end = intervals[i].second;
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}