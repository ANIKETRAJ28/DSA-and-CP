#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/gas-station/

class Solution
{
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
  {
    int n = gas.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += gas[i] - cost[i];
    }
    if (sum < 0)
      return -1;
    sum = 0;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
      sum += gas[i] - cost[i];
      if (sum < 0)
      {
        idx = i + 1;
        sum = 0;
      }
    }
    return idx;
  }
};

int main()
{

  return 0;
}