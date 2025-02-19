#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/next-greater-element-ii/

class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && st.top().first < nums[i])
      {
        ans[st.top().second] = nums[i];
        st.pop();
      }
      st.push({nums[i], i});
    }
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && st.top().first < nums[i])
      {
        ans[st.top().second] = nums[i];
        st.pop();
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}