#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int n = matrix.size();
    int m = matrix[0].size();
    int lo = 0, hi = n - 1;
    int row = -1;
    while (lo <= hi)
    {
      int mid = lo + (hi - lo) / 2;
      if (matrix[mid][0] > target)
        hi = mid - 1;
      else
      {
        row = mid;
        lo = mid + 1;
      }
    }
    if (row == -1)
      return false;
    lo = 0, hi = m - 1;
    while (lo <= hi)
    {
      int mid = lo + (hi - lo) / 2;
      if (matrix[row][mid] == target)
        return true;
      else if (matrix[row][mid] < target)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
    return false;
  }
};

int main()
{

  return 0;
}