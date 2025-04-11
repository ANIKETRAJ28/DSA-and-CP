#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
class Solution
{
public:
  int minMoves(vector<int> &nums)
  {
    int minNum = INT_MAX;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      minNum = min(minNum, nums[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans += (nums[i] - minNum);
    }
    return ans;
  }
};

int main()
{

  return 0;
}