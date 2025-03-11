#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

class Solution
{
public:
  int subarraysDivByK(vector<int> &nums, int k)
  {
    int n = nums.size();
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      sum = (sum + nums[i]) % k;
      if (sum < 0)
        sum += k;
      if (mp.find(sum) != mp.end())
      {
        cnt += mp[sum];
      }
      mp[sum]++;
    }
    return cnt;
  }
};

int main()
{

  return 0;
}