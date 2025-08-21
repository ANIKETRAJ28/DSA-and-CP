#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/snakes-and-ladders/

class Solution
{
public:
  pair<int, int> findPos(int idx, int n)
  {
    int row = n - 1 - idx / n;
    int col = idx % n;
    if ((n - row - 1) % 2)
      col = n - col - 1;
    return {row, col};
  }
  int snakesAndLadders(vector<vector<int>> &board)
  {
    int n = board.size();
    queue<pair<int, int>> qu;
    qu.push({0, 0});
    vector<bool> visited(n * n, 0);
    while (!qu.empty())
    {
      pair<int, int> front = qu.front();
      int idx = front.first;
      int cnt = front.second;
      qu.pop();
      if (idx == n * n - 1)
        return cnt;
      if (visited[idx])
        continue;
      visited[idx] = 1;
      for (int i = 1; i <= 6; i++)
      {
        int next_idx = idx + i;
        if (next_idx >= n * n)
          break;
        pair<int, int> next_pos = findPos(next_idx, n);
        int next_row = next_pos.first;
        int next_col = next_pos.second;
        if (board[next_row][next_col] != -1)
        {
          next_idx = board[next_row][next_col] - 1;
        }
        if (!visited[next_idx])
          qu.push({next_idx, cnt + 1});
      }
    }
    return -1;
  }
};

int main()
{

  return 0;
}