#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-erasure-value/description/

class Solution
{
public:
  int maximumUniqueSubarray(vector<int> &nums)
  {
    int sum = 0;
    int currSum = 0;
    int n = nums.size();
    unordered_set<int> st;
    int i = 0, j = 0;
    while (j < n)
    {
      if (st.find(nums[j]) == st.end())
      {
        st.insert(nums[j]);
        currSum += nums[j];
      }
      else
      {
        while (i < j && nums[i] != nums[j])
        {
          st.erase(nums[i]);
          currSum -= nums[i];
          i++;
        }
        i++;
      }
      sum = max(sum, currSum);
      j++;
    }
    return sum;
  }
};

class Solution
{
public:
  int partitionString(string s)
  {
    int n = s.size();
    unordered_set<char> st;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (st.find(s[i]) == st.end())
        st.insert(s[i]);
      else
      {
        cnt++;
        st.clear();
        st.insert(s[i]);
      }
    }
    return ++cnt;
  }
};

int main()
{

  return 0;
}