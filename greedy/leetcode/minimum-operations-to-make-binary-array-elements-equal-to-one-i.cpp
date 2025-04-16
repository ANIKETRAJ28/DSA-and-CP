#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/

class Solution
{
public:
  int minOperations(vector<int> &nums)
  {
    int n = nums.size();
    int cnt = 0;
    for (int i = 2; i < n; i++)
    {
      if (nums[i - 2] == 0)
      {
        nums[i - 2] = !nums[i - 2];
        nums[i - 1] = !nums[i - 1];
        nums[i] = !nums[i];
        cnt++;
      }
    }
    for (auto el : nums)
      if (el == 0)
        return -1;
    return cnt;
  }
};

int main()
{

  return 0;
}