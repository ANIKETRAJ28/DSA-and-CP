#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-time-to-complete-trips/description/

class Solution
{
public:
  bool canTrip(vector<int> &time, int trip, long long t)
  {
    int n = time.size();
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans += t / (long long)time[i];
      if (ans >= trip)
        return true;
    }
    return false;
  }
  long long minimumTime(vector<int> &time, int totalTrips)
  {
    int n = time.size();
    long long lo = 1, hi = 1;
    for (int i = 0; i < n; i++)
    {
      hi = max(hi, (long long)time[i]);
    }
    hi *= totalTrips;
    long long ans = -1;
    while (lo <= hi)
    {
      long long mid = lo + (hi - lo) / 2;
      if (canTrip(time, totalTrips, mid))
      {
        ans = mid;
        hi = mid - 1;
      }
      else
      {
        lo = mid + 1;
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}