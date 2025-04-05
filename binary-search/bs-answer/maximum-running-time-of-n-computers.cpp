#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-running-time-of-n-computers/description/

class Solution
{
public:
  bool canMake(vector<int> &batteries, int comp, long long mins)
  {
    int n = batteries.size();
    long long minMins = 0;
    for (int b : batteries)
    {
      minMins += min((long long)b, mins);
      if (minMins >= mins * comp)
        return true;
    }
    return false;
  }
  long long maxRunTime(int n, vector<int> &batteries)
  {
    int m = batteries.size();
    long long lo = 0, hi = 0;
    for (int b : batteries)
    {
      hi += b;
    }
    hi /= n;
    long long ans = lo;
    while (lo <= hi)
    {
      long long mid = lo + (hi - lo) / 2;
      if (canMake(batteries, n, mid))
      {
        ans = mid;
        lo = mid + 1;
      }
      else
      {
        hi = mid - 1;
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}