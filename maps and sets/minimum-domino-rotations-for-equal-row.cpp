#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

class Solution
{
public:
  int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
  {
    int n = tops.size();
    int mid = n % 2 ? n / 2 + 1 : n / 2;
    vector<int> topFreq(7, 0), bottomFreq(7, 0);
    for (int i = 0; i < n; i++)
    {
      topFreq[tops[i]]++;
      bottomFreq[bottoms[i]]++;
    }
    int val1 = INT_MAX, swap1 = INT_MAX;
    int val2 = INT_MAX, swap2 = INT_MAX;
    for (int i = 0; i < 7; i++)
    {
      if (topFreq[i] >= mid)
      {
        val1 = i;
      }
      if (bottomFreq[i] >= mid)
      {
        val2 = i;
      }
    }
    if (val1 == INT_MAX && val2 == INT_MAX)
      return -1;
    if (val1 != INT_MAX)
    {
      bool flag = true;
      for (int i = 0; i < n; i++)
      {
        if (tops[i] != val1 && bottoms[i] != val1)
        {
          flag = false;
          break;
        }
      }
      if (flag)
        swap1 = n - topFreq[val1];
    }
    if (val2 != INT_MAX)
    {
      bool flag = true;
      for (int i = 0; i < n; i++)
      {
        if (bottoms[i] != val2 && tops[i] != val2)
        {
          flag = false;
          break;
        }
      }
      if (flag)
        swap2 = n - bottomFreq[val2];
    }
    if (swap1 == INT_MAX && swap2 == INT_MAX)
      return -1;
    return min(swap1, swap2);
  }
};

int main()
{

  return 0;
}