#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/

class Solution
{
public:
  int minimumDeletions(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return 1;
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    int maxIdx = -1, minIdx = -1;
    for (int i = 0; i < n; i++)
    {
      if (nums[i] < minVal)
      {
        minVal = nums[i];
        minIdx = i;
      }
      if (nums[i] > maxVal)
      {
        maxVal = nums[i];
        maxIdx = i;
      }
    }
    if (maxIdx < minIdx)
      swap(minIdx, maxIdx);
    return min(maxIdx + 1, min(n - minIdx, minIdx + 1 + n - maxIdx));
  }
};

int main()
{

  return 0;
}