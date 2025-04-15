#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/

class Solution
{
public:
  int moves(unordered_map<int, int> &mp, int prvEle, int currEle)
  {
    int cnt = 0;
    for (int i = prvEle + 1; i < currEle && mp.size(); i++)
    {
      auto ele = mp.begin();
      int val = ele->first;
      int freq = ele->second;
      cnt += i - val;
      freq--;
      if (freq == 0)
        mp.erase(ele);
      else
        mp[val] = freq;
    }
    return cnt;
  }
  int minIncrementForUnique(vector<int> &nums)
  {
    int n = nums.size();
    unordered_map<int, int> mp;
    sort(nums.begin(), nums.end());
    int ans = 0;
    int prvEle = nums[0];
    for (int i = 1; i < n; i++)
    {
      if (nums[i] == prvEle + 1)
      {
        prvEle = nums[i];
      }
      else if (nums[i] == prvEle)
      {
        mp[nums[i]]++;
      }
      else
      {
        ans += moves(mp, prvEle, nums[i]);
        prvEle = nums[i];
      }
    }
    while (mp.size())
    {
      auto ele = mp.begin();
      int val = ele->first;
      int freq = ele->second;
      int diff = prvEle - val;
      ans += diff * freq;
      ans += freq * (freq + 1) / 2;
      prvEle += freq;
      mp.erase(val);
    }
    return ans;
  }
};

int main()
{

  return 0;
}