#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

class Solution
{
public:
  bool canDistribute(vector<int> &quantities, int q, int n)
  {
    int m = quantities.size();
    long long int quantity = 0;
    for (int i = 0; i < m; i++)
    {
      quantity += quantities[i] / q;
      if (quantities[i] % q)
        quantity++;
      if (quantity > n)
        return false;
    }
    return true;
  }
  int minimizedMaximum(int n, vector<int> &quantities)
  {
    int m = quantities.size();
    int lo = 1, hi = 100000;
    int ans = 0;
    while (lo <= hi)
    {
      int mid = lo + (hi - lo) / 2;
      if (canDistribute(quantities, mid, n))
      {
        ans = mid;
        hi = mid - 1;
      }
      else
      {
        lo = mid + 1;
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}