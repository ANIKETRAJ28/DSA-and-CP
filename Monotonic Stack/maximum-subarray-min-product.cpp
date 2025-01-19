#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-subarray-min-product/description/

class Solution
{
public:
  int maxSumMinProduct(vector<int> &nums)
  {
    int n = nums.size();
    vector<long long int> prefix(n + 1, 0);
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
      prefix[i + 1] = prefix[i] + nums[i];
    }
    long long int res = 0;
    for (int i = 0; i < n; i++)
    {
      int newStrt = i;
      while (!st.empty() && st.top().second > nums[i])
      {
        pair<int, int> ele = st.top();
        st.pop();
        long long int sum = prefix[i] - prefix[ele.first];
        res = max(res, sum * ele.second);
        newStrt = ele.first;
      }
      st.push({newStrt, nums[i]});
    }
    while (!st.empty())
    {
      pair<int, int> ele = st.top();
      st.pop();
      long long int sum = prefix[n] - prefix[ele.first];
      res = max(res, sum * ele.second);
    }
    return res % 1000000007;
  }
};

int main()
{

  return 0;
}