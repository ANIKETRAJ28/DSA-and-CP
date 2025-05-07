#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/

class Solution
{
public:
  vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  int minTimeToReach(vector<vector<int>> &nums)
  {
    int n = nums.size();
    int m = nums[0].size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, 0});
    while (!pq.empty())
    {
      vector<int> curr = pq.top();
      pq.pop();
      int time = curr[0], row = curr[1], col = curr[2];
      if (time >= dp[row][col])
        continue;
      if (row == n - 1 && col == m - 1)
        return time;
      dp[row][col] = time;
      for (auto d : dir)
      {
        int nextR = row + d[0];
        int nextC = col + d[1];
        if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && dp[nextR][nextC] == INT_MAX)
        {
          int nextT = max(nums[nextR][nextC], time) + 1;
          pq.push({nextT, nextR, nextC});
        }
      }
    }
    return 0;
  }
};

int main()
{

  return 0;
}