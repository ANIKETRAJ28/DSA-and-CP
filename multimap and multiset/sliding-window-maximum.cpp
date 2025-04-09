#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/sliding-window-maximum/description/

class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<int> ans;
    multiset<int> st;
    int j = 0, i = 0;
    for (i; i < k; i++)
    {
      st.insert(nums[i]);
    }
    while (i < n)
    {
      ans.push_back(*st.rbegin());
      st.erase(st.find(nums[j]));
      st.insert(nums[i]);
      i++;
      j++;
    }
    ans.push_back(*st.rbegin());
    return ans;
  }
};

int main()
{

  return 0;
}