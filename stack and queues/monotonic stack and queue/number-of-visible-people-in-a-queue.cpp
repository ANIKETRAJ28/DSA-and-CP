#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/number-of-visible-people-in-a-queue/description/

class Solution
{
public:
  vector<int> canSeePersonsCount(vector<int> &nums)
  {
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, 0);
    st.push(nums[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
      int cnt = 0;
      while (!st.empty() && nums[i] > st.top())
      {
        cnt++;
        st.pop();
      }
      cnt += !st.empty();
      ans[i] = cnt;
      st.push(nums[i]);
    }
    return ans;
  }
};

int main()
{

  return 0;
}