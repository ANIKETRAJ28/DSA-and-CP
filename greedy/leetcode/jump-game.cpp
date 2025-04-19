#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/jump-game/description/

class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int n = nums.size();
    int currJump = 0, maxJump = 0;
    for (int i = 0; i < n; i++)
    {
      if (i > currJump)
        return false;
      maxJump = max(maxJump, i + nums[i]);
      if (currJump == i)
      {
        currJump = maxJump;
      }
    }
    return true;
  }
};

int main()
{

  return 0;
}