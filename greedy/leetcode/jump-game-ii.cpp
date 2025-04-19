#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/jump-game-ii/description/

class Solution
{
public:
  int jump(vector<int> &nums)
  {
    int n = nums.size();
    int currJump = 0, maxJump = 0, jumps = 0;
    for (int i = 0; i < n - 1; i++)
    {
      maxJump = max(maxJump, i + nums[i]);
      if (currJump == i)
      {
        jumps++;
        currJump = maxJump;
      }
    }
    return jumps;
  }
};

int main()
{

  return 0;
}