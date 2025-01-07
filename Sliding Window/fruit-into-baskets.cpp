#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

class Solution
{
public:
  int totalFruits(vector<int> &arr)
  {
    // code here
    int n = arr.size();
    int i = 0, j = 0;
    int cnt = 0;
    pair<int, int> b1 = {INT_MAX, INT_MAX}, b2 = {INT_MAX, INT_MAX};
    while (j < n)
    {
      if (b1.first == INT_MAX)
      {
        b1 = {arr[j], j};
      }
      else if (arr[j] == b1.first)
      {
        b1.second = j;
      }
      else if (b2.first == INT_MAX)
      {
        b2 = {arr[j], j};
      }
      else if (arr[j] == b2.first)
      {
        b2.second = j;
      }
      else
      {
        cnt = max(cnt, j - i);
        if (b1.second >= b2.second)
        {
          swap(b1, b2);
          i = b1.second + 1;
          b1.first = arr[j];
          b1.second = j;
        }
      }
      j++;
      return max(cnt, j - i);
    }
  }
};
int main()
{

  return 0;
}