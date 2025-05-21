#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/assign-cookies

class Solution
{
public:
  int findContentChildren(vector<int> &g, vector<int> &s)
  {
    int n = g.size();
    int m = s.size();
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    int cnt = 0;
    while (i < n && j < m)
    {
      if (s[j] >= g[i])
      {
        cnt++;
        i++;
      }
      j++;
    }
    return cnt;
  }
};

int main()
{

  return 0;
}