#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description

class Solution
{
public:
  long long maximumTripletValue(vector<int> &nums)
  {
    int n = nums.size();
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (nums[i] <= nums[j])
          continue;
        for (int k = j + 1; k < n; k++)
        {
          ans = max(ans, (long long)(nums[i] - nums[j]) * nums[k]);
        }
      }
    }
    return ans;
  }
};

class Solution
{
public:
  long long maximumTripletValue(vector<int> &nums)
  {
    long long maxTriplet = 0, maxEle = 0, maxDiff = 0;
    for (long long n : nums)
    {
      maxTriplet = max(maxTriplet, n * maxDiff);
      maxDiff = max(maxDiff, maxEle - n);
      maxEle = max(maxEle, n);
    }
    return maxTriplet;
  }
};

int main()
{

  return 0;
}