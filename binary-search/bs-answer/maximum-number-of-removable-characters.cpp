#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-number-of-removable-characters/description/

class Solution
{
public:
  bool canMake(string &s, string &t, vector<bool> &flag)
  {
    int n = s.size();
    int m = t.size();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
      if (s[i] == t[j] && flag[i])
        j++;
      i++;
    }
    return j == m;
  }
  int maximumRemovals(string s, string p, vector<int> &removable)
  {
    int n = s.size();
    int m = p.size();
    int lo = 0, hi = removable.size() - 1;
    int ans = 0;
    while (lo <= hi)
    {
      int mid = lo + (hi - lo) / 2;
      vector<bool> flag(n, 1);
      for (int i = 0; i <= mid; i++)
      {
        flag[removable[i]] = 0;
      }
      if (canMake(s, p, flag))
      {
        ans = mid + 1;
        lo = mid + 1;
      }
      else
      {
        hi = mid - 1;
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}