#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/sliding-window-maximum/description

class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
      // remove the front elements which are of no use
      while (!dq.empty() && dq.front() <= i - k)
        dq.pop_front();
      // remove the back elements which are smaller
      while (!dq.empty() && nums[dq.back()] < nums[i])
        dq.pop_back();
      // now all are increasing and push current element
      dq.push_back(i);
      if (i >= k - 1)
        ans.push_back(nums[dq.front()]);
    }
    return ans;
  }
};

int main()
{

  return 0;
}