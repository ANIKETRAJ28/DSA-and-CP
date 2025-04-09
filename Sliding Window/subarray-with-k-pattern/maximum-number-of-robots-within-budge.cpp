#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-number-of-robots-within-budget/description/

class Solution
{
public:
#define ll long long
  int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
  {
    int n = chargeTimes.size();
    vector<ll> cost(n, 0);
    multiset<int> st;
    cost[0] = runningCosts[0];
    for (int i = 1; i < n; i++)
      cost[i] = cost[i - 1] + runningCosts[i];
    int ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
      st.insert(chargeTimes[i]);
      ll currBudget = *st.rbegin() + (i - j + 1) * (cost[i] - (j == 0 ? 0 : cost[j - 1]));
      if (currBudget <= budget)
      {
        ans = max(ans, i - j + 1);
      }
      else
      {
        while (j <= i)
        {
          st.erase(st.find(chargeTimes[j]));
          j++;
          if (j > i)
            break;
          ll tempBudget = *st.rbegin() + (i - j + 1) * (cost[i] - cost[j - 1]);
          if (tempBudget <= budget)
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