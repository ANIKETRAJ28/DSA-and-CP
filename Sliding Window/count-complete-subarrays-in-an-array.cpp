#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-complete-subarrays-in-an-array/

class Solution
{
public:
  int countCompleteSubarrays(vector<int> &nums)
  {
    int n = nums.size();
    unordered_set<int> st;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
      st.insert(nums[i]);
    int i = 0, j = 0;
    int cnt = 0;
    while (j < n)
    {
      mp[nums[j]]++;
      while (i <= j && mp.size() == st.size())
      {
        cnt += n - j;
        mp[nums[i]]--;
        if (mp[nums[i]] == 0)
          mp.erase(nums[i]);
        i++;
      }
      j++;
    }
    return cnt;
  }
};

int main()
{

  return 0;
}