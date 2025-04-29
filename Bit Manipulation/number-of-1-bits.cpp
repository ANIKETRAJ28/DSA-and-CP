#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/number-of-1-bits/description/

class Solution
{
public:
  int hammingWeight(int n)
  {
    int cnt = 0;
    while (n)
    {
      cnt++;
      n = n & n - 1;
    }
    return cnt;
  }
};

int main()
{

  return 0;
}