#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-sum-circular-subarray/description/

class Solution
{
public:
  int maxSubarraySumCircular(vector<int> &nums)
  {
    int n = nums.size();
    int sumMin = 0, sumMax = 0, minSum = INT_MAX, maxSum = INT_MIN, totalSum = 0;
    for (int i = 0; i < n; i++)
    {
      sumMin += nums[i];
      sumMax += nums[i];
      maxSum = max(maxSum, sumMax);
      minSum = min(minSum, sumMin);
      if (sumMin > 0)
        sumMin = 0;
      if (sumMax < 0)
        sumMax = 0;
      totalSum += nums[i];
    }
    return totalSum - minSum == 0 ? maxSum : max(maxSum, totalSum - minSum);
  }
};

int main()
{

  return 0;
}