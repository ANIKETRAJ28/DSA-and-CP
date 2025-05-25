#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/

class Solution
{
public:
  int minDifference(vector<int> &nums)
  {
    int n = nums.size();
    if (n < 4)
      return 0;
    sort(nums.begin(), nums.end());
    int ans = INT_MAX;
    int cnt = 0;
    for (int i = n - 4; i < n; i++, cnt++)
    {
      ans = min(ans, nums[i] - nums[cnt]);
    }
    return ans;
  }
};

int main()
{

  return 0;
}