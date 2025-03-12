#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-number-of-bad-pairs/description/

class Solution
{
public:
  long long countBadPairs(vector<int> &nums)
  {
    unordered_map<int, int> mp;
    long long goodPairs = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
      int key = nums[i] - i;
      goodPairs += mp[key];
      mp[key]++;
    }
    return (n * (n - 1)) / 2 - goodPairs;
  }
};

int main()
{

  return 0;
}