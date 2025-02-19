#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/daily-temperatures/description/

class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &nums)
  {
    int n = nums.size();
    stack<pair<int, int>> st;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && nums[i] > st.top().first)
      {
        ans[st.top().second] = i - st.top().second;
        st.pop();
      }
      st.push({nums[i], i});
    }
    return ans;
  }
};

int main()
{

  return 0;
}