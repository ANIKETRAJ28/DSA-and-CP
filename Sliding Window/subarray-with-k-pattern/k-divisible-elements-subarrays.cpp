#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/k-divisible-elements-subarrays/

class Solution
{
public:
  int countDistinct(vector<int> &nums, int k, int p)
  {
    int n = nums.size();
    set<vector<int>> st;
    int i = 0, j = 0;
    for (int j = 0; j < n; j++)
    {
      vector<int> subArray;
      int kCnt = 0;
      for (int i = j; i < n; i++)
      {
        subArray.push_back(nums[i]);
        if (nums[i] % p == 0)
          kCnt++;
        if (kCnt > k)
          break;
        st.insert(subArray);
      }
    }
    return st.size();
  }
};

int main()
{

  return 0;
}