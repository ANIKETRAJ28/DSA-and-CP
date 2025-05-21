#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1

class Solution
{
public:
  vector<int> candyStore(int candies[], int n, int k)
  {
    // Write Your Code here
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      v[i] = candies[i];
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    int ans1 = 0;
    while (i <= j)
    {
      ans1 += v[i];
      for (int x = 0; x < k && j >= i; x++)
      {
        j--;
      }
      i++;
    }
    i = n - 1, j = 0;
    int ans2 = 0;
    while (i >= j)
    {
      ans2 += v[i];
      for (int x = 0; x < k && j <= i; x++)
      {
        j++;
      }
      i--;
    }
    return {ans1, ans2};
  }
};

int main()
{

  return 0;
}