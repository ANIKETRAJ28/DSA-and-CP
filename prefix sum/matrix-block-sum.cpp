#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/matrix-block-sum/description/

class Solution
{
public:
  // int getSum(vector<vector<int>> &nums, int r1, int r2, int c1, int c2) {
  //     int ans = 0;
  //     for(int i = r1 ; i <= r2 ; i++) {
  //         for(int j = c1 ; j <= c2 ; j++) {
  //             ans += nums[i][j];
  //         }
  //     }
  //     return ans;
  // }

  int getSum(vector<vector<int>> &nums, int minR, int maxR, int minC, int maxC)
  {
    int sum = nums[maxR][maxC];

    if (minR > 0)
      sum -= nums[minR - 1][maxC];
    if (minC > 0)
      sum -= nums[maxR][minC - 1];
    if (minR > 0 && minC > 0)
      sum += nums[minR - 1][minC - 1];

    return sum;
  }

  vector<vector<int>> matrixBlockSum(vector<vector<int>> &nums, int k)
  {
    int n = nums.size();
    int m = nums[0].size();
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
      for (int j = 1; j < m; j++)
      {
        nums[i][j] += nums[i][j - 1];
      }
    }
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        nums[i][j] += nums[i - 1][j];
      }
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int minR = max(0, i - k);
        int minC = max(0, j - k);
        int maxR = min(n - 1, i + k);
        int maxC = min(m - 1, j + k);
        ans[i][j] = getSum(nums, minR, maxR, minC, maxC);
      }
    }
    // for(int i = 0 ; i < n ; i++) {
    //     for(int j = 0 ; j < m ; j++) {
    //         int minR = 0, minC = 0, maxR = n-1, maxC = m-1;
    //         minR = max(minR, i-k);
    //         minC = max(minC, j-k);
    //         maxR = min(maxR, i+k);
    //         maxC = min(maxC, j+k);
    //         ans[i][j] = getSum(nums, minR, maxR, minC, maxC);
    //     }
    // }
    return ans;
  }
};

int main()
{

  return 0;
}