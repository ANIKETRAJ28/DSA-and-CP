#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

class Solution
{
public:
  long long maximumSubarraySum(vector<int> &nums, int k)
  {
    int n = nums.size();
    set<int> st;
    long long sum = 0, ans = 0;
    int i = 0, j = 0;
    while (j < n)
    {
      while (i < j && (st.size() >= k || st.find(nums[j]) != st.end()))
      {
        sum -= nums[i];
        st.erase(nums[i]);
        i++;
      }
      st.insert(nums[j]);
      sum += nums[j];
      if (st.size() == k)
        ans = max(ans, sum);
      j++;
    }
    return ans;
  }
};

int main()
{

  return 0;
}