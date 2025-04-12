#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/description/

class Solution
{
public:
  bool isPossible(vector<int> &workers, vector<int> &tasks, int strength, int pill, int mid)
  {
    multiset<int> ms(workers.end() - mid, workers.end());
    for (int i = mid - 1; i >= 0; i--)
    {
      // it will point to the end of the multiset, so to retreive the last element we do it--
      auto it = ms.end();
      it--;
      if (*it < tasks[i])
      {
        if (!pill)
          return false;
        // lower_bound gives the element which is just >= case
        // so, here it will give the element which is just greater or equal to the worker with the (tasks[i]-strength)
        // if not present it will point to the end
        it = ms.lower_bound(tasks[i] - strength);
        if (it == ms.end())
          return false;
        pill--;
      }
      ms.erase(it);
    }
    return true;
  }
  int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
  {
    int n = tasks.size();
    int m = workers.size();
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());
    int lo = 0, hi = min(n, m);
    int ans = 0;
    while (lo <= hi)
    {
      int mid = lo + (hi - lo) / 2;
      if (isPossible(workers, tasks, strength, pills, mid))
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