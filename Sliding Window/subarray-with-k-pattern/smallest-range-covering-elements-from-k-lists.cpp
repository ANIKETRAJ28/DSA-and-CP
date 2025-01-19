#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

class Solution
{
public:
  vector<int> smallestRange(vector<vector<int>> &nums)
  {
    int n = nums.size();
    vector<pair<int, int>> merge;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < nums[i].size(); j++)
      {
        merge.push_back({nums[i][j], i});
      }
    }
    sort(merge.begin(), merge.end());
    unordered_map<int, int> mp;
    vector<int> minWindow = {-1, -1};
    int minVal = INT_MAX;
    for (int i = 0; i < merge.size(); i++)
    {
      pair<int, int> ele = merge[i];
      mp[ele.second] = ele.first;
      if (mp.size() == n)
      {
        int mini = INT_MAX, maxi = INT_MIN;
        for (auto el = mp.begin(); el != mp.end(); el++)
        {
          mini = min(mini, el->second);
          maxi = max(maxi, el->second);
        }
        if (maxi - mini < minVal)
        {
          minVal = maxi - mini;
          minWindow = {mini, maxi};
        }
      }
    }
    return minWindow;
  }
};

int main()
{

  return 0;
}