#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-penalty-for-a-shop/

class Solution
{
public:
  int bestClosingTime(string customers)
  {
    int n = customers.size();
    vector<int> pre(n + 1, 0), suf(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
      pre[i] += pre[i - 1] + (customers[i - 1] == 'N');
    }
    pre[n] = pre[n - 1] + (customers[n - 1] == 'N');
    suf[n - 1] = customers[n - 1] == 'Y';
    for (int i = n - 2; i >= 0; i--)
    {
      suf[i] += suf[i + 1] + (customers[i] == 'Y');
    }
    int minPenalty = INT_MAX, ans = 0;
    for (int i = 0; i <= n; i++)
    {
      if (pre[i] + suf[i] < minPenalty)
      {
        minPenalty = pre[i] + suf[i];
        ans = i;
      }
    }
    return ans;
  }
};

class Solution
{
public:
  int bestClosingTime(string customers)
  {
    int n = customers.size();
    vector<int> penalty(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
      penalty[i] = penalty[i - 1] + (customers[i - 1] == 'N');
    }
    penalty[n] = penalty[n - 1] + (customers[n - 1] == 'N');
    int x = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      x += (customers[i] == 'Y');
      penalty[i] += x;
    }
    int minPenalty = INT_MAX;
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
      if (penalty[i] < minPenalty)
      {
        ans = i;
        minPenalty = penalty[i];
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}