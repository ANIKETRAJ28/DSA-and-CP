#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1;
    while (row < n && col >= 0)
    {
      if (matrix[row][col] == target)
        return true;
      else if (matrix[row][col] < target)
        row++;
      else
        col--;
    }
    return false;
  }
};

int main()
{

  return 0;
}