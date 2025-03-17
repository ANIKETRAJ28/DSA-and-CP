#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/range-sum-query-2d-immutable/description/

class NumMatrix
{
public:
  vector<vector<int>> mat;
  NumMatrix(vector<vector<int>> &matrix)
  {
    mat = matrix;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 1; j < m; j++)
      {
        mat[i][j] += mat[i][j - 1];
      }
    }
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        mat[i][j] += mat[i - 1][j];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    int rangeSum = mat[row2][col2];
    int leftSum = 0;
    int upSum = 0;
    int extraSum = 0;
    if (col1 - 1 >= 0)
      leftSum += mat[row2][col1 - 1];
    if (row1 - 1 >= 0)
      upSum += mat[row1 - 1][col2];
    if (row1 - 1 >= 0 && col1 - 1 >= 0)
      extraSum += mat[row1 - 1][col1 - 1];
    return rangeSum - leftSum - upSum + extraSum;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main()
{

  return 0;
}