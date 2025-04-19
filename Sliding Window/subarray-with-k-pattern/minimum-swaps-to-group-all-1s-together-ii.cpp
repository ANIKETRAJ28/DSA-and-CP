#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

class Solution
{
public:
  int minSwaps(vector<int> &arr)
  {
    int n = arr.size();
    int totalOnes = 0;
    for (int i = 0; i < n; i++)
    {
      if (arr[i])
        totalOnes++;
    }
    int swaps = INT_MAX;
    int ones = 0;
    for (int i = 0; i < totalOnes; i++)
    {
      if (arr[i])
        ones++;
    }
    swaps = min(swaps, totalOnes - ones);
    int i = 0, j = totalOnes;
    while (j < n)
    {
      if (arr[i])
        ones--;
      if (arr[j])
        ones++;
      swaps = min(swaps, totalOnes - ones);
      j++;
      i++;
    }
    ones = 0;
    for (i = 0; i < totalOnes; i++)
    {
      if (arr[i])
        ones++;
    }
    i = totalOnes - 1, j = n - 1;
    while (i >= 0)
    {
      if (arr[i])
        ones--;
      if (arr[j])
        ones++;
      swaps = min(swaps, totalOnes - ones);
      i--;
      j--;
    }
    return swaps;
  }
};

int main()
{

  return 0;
}