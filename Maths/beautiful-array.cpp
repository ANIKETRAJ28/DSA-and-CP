#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/beautiful-array/description/

class Solution
{
public:
  vector<int> beautifulArray(int n)
  {
    vector<int> res = {1};
    while (res.size() < n)
    {
      vector<int> curr;
      for (int e : res)
      {
        if (e * 2 - 1 <= n)
          curr.push_back(e * 2 - 1);
      }
      for (int e : res)
      {
        if (e * 2 <= n)
          curr.push_back(e * 2);
      }
      res = curr;
    }
    return res;
  }
};

int main()
{

  return 0;
}