#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/jump-game-iii/description/

class Solution
{
public:
  vector<bool> visited;
  bool find(vector<int> &arr, int start)
  {
    int n = arr.size();
    if (arr[start] == 0)
      return true;
    visited[start] = true;
    bool left = false;
    if (start - arr[start] >= 0 && !visited[start - arr[start]])
      left = canReach(arr, start - arr[start]);
    if (left)
      return left;
    bool right = false;
    if (start + arr[start] < n && !visited[start + arr[start]])
      right = canReach(arr, start + arr[start]);
    return right;
  }
  bool canReach(vector<int> &arr, int start)
  {
    int n = arr.size();
    visited.resize(n, false);
    return find(arr, start);
  }
};

int main()
{

  return 0;
}