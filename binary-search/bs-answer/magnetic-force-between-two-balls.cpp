#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/magnetic-force-between-two-balls/description/

class Solution
{
public:
  bool canPlace(vector<int> &nums, int force, int m)
  {
    int n = nums.size();
    int prvPos = nums[0];
    for (int i = 1; i < n; i++)
    {
      if (nums[i] - prvPos >= force)
      {
        prvPos = nums[i];
        m--;
      }
      if (m == 0)
        return true;
    }
    return false;
  }

  int maxDistance(vector<int> &position, int m)
  {
    int n = position.size();
    sort(position.begin(), position.end());
    int ans = 0;
    int lo = 1, hi = position[n - 1];
    while (lo <= hi)
    {
      int mid = lo + (hi - lo) / 2;
      if (canPlace(position, mid, m - 1))
      {
        ans = max(ans, mid);
        lo = mid + 1;
      }
      else
      {
        hi = mid - 1;
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}