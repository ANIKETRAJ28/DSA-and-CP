#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/separate-black-and-white-balls/description/

class Solution
{
public:
  long long minimumSteps(string s)
  {
    long long ones = 0, ans = 0;
    for (char n : s)
    {
      if (n == '1')
      {
        ones++;
        continue;
      }
      ans += ones;
    }
    return ans;
  }
};

int main()
{

  return 0;
}