#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

class Solution
{
public:
  int maxAbsoluteSum(vector<int> &nums)
  {
    int n = nums.size();
    int sum = 0, minSum = 0, maxSum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += nums[i];
      maxSum = max(maxSum, sum);
      if (sum < 0)
        sum = 0;
    }
    sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += nums[i];
      minSum = min(minSum, sum);
      if (sum > 0)
        sum = 0;
    }
    return max(maxSum, abs(minSum));
  }
};

int main()
{

  return 0;
}