#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-the-number-of-copy-arrays/description/

class Solution
{
public:
  int countArrays(vector<int> &original, vector<vector<int>> &bounds)
  {
    int n = original.size();
    int minBound = bounds[0][0], maxBound = bounds[0][1];
    int diff = 0;
    for (int i = 1; i < n; i++)
    {
      diff += original[i] - original[i - 1];
      minBound = max(minBound, bounds[i][0] - diff);
      maxBound = min(maxBound, bounds[i][1] - diff);
    }
    return maxBound < minBound ? 0 : maxBound - minBound + 1;
  }
};

int main()
{

  return 0;
}