#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://www.codechef.com/problems/BPHC03

bool isSafe(vector<vector<int>> &maze, int i, int j)
{
  int n = maze.size();
  return i >= 0 && i < n && j >= 0 && j < n && maze[i][j] == 0;
}

int find(vector<vector<int>> &maze, int i, int j)
{
  int n = maze.size();
  if (!isSafe(maze, i, j))
    return 0;
  if (i == n - 1 && j == n - 1)
    return 1;
  int ans = 0;
  // mark visited
  maze[i][j] = -1;
  // up
  if (isSafe(maze, i, j + 1))
    ans += find(maze, i, j + 1);
  // down
  if (isSafe(maze, i, j - 1))
    ans += find(maze, i, j - 1);
  // left
  if (isSafe(maze, i - 1, j))
    ans += find(maze, i - 1, j);
  // right
  if (isSafe(maze, i + 1, j))
    ans += find(maze, i + 1, j);
  // unmark visited
  maze[i][j] = 0;
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> maze(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> maze[i][j];
    }
  }
  cout << find(maze, 0, 0);
  return 0;
}