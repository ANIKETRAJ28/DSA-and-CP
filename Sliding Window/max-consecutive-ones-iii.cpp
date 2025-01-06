#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/max-consecutive-ones-iii/description/

class Solution
{
public:
  int longestOnes(vector<int> &nums, int k)
  {
    int n = nums.size();
    int len = 0;
    int i = 0, j = 0;
    int kCnt = k;
    while (j < n)
    {
      if (nums[j] == 1)
      {
        j++;
      }
      else
      {
        if (kCnt != 0)
        {
          kCnt--;
          j++;
        }
        else
        {
          len = max(len, j - i);
          while (nums[i] == 1)
          {
            i++;
          }
          kCnt++;
          i++;
        }
      }
    }
    return max(len, j - i);
  }
};

int main()
{

  return 0;
}