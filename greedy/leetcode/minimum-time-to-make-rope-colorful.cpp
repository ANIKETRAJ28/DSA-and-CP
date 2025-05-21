#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/

class Solution
{
public:
  int minCost(string colors, vector<int> &neededTime)
  {
    int n = colors.size();
    int prv = 0;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
      if (colors[prv] == colors[i])
      {
        ans += min(neededTime[i], neededTime[prv]);
        if (neededTime[i] > neededTime[prv])
          prv = i;
      }
      else
      {
        prv = i;
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}