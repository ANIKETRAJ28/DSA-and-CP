#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/next-greater-element-i/

class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    int n1 = nums1.size();
    int n2 = nums2.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n2; i++)
    {
      mp[nums2[i]] = i;
    }
    vector<int> ans(n1, -1);
    for (int i = 0; i < n1; i++)
    {
      if (mp.find(nums1[i]) == mp.end())
        continue;
      int idx = mp[nums1[i]];
      for (int j = idx + 1; j < n2; j++)
      {
        if (nums2[j] > nums1[i])
        {
          ans[i] = nums2[j];
          break;
        }
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}