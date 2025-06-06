#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/contains-duplicate-iii

class Solution
{
public:
#define ll long long int
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
  {
    int n = nums.size();
    set<ll> st;
    for (int i = 0; i < n; i++)
    {
      if (i > indexDiff)
        st.erase(nums[i - indexDiff - 1]);
      auto it = st.lower_bound(nums[i] - valueDiff);
      if (it != st.end() && (*it - nums[i]) <= valueDiff)
        return true;
      st.insert(nums[i]);
    }
    return false;
  }
};

int main()
{

  return 0;
}