#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/next-greater-element-i/description/

class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    int n1 = nums1.size();
    int n2 = nums2.size();
    unordered_map<int, int> mp;
    stack<int> st;
    vector<int> ans(n1, -1);
    for (int i = 0; i < n1; i++)
    {
      mp[nums1[i]] = i;
    }
    for (int i = 0; i < n2; i++)
    {
      while (!st.empty() && nums2[i] > st.top())
      {
        ans[mp[st.top()]] = nums2[i];
        st.pop();
      }
      if (mp.find(nums2[i]) != mp.end())
        st.push(nums2[i]);
    }
    return ans;
  }
};

int main()
{

  return 0;
}