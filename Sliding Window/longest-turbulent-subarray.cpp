#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/longest-turbulent-subarray/

class Solution
{
public:
  int maxTurbulenceSize(vector<int> &arr)
  {
    int n = arr.size();
    int l = 0, r = 1;
    string prv = "";
    int res = 1;
    while (r < n)
    {
      if (arr[r - 1] < arr[r] && prv != "<")
      {
        res = max(res, r - l + 1);
        prv = "<";
      }
      else if (arr[r - 1] > arr[r] && prv != ">")
      {
        res = max(res, r - l + 1);
        prv = ">";
      }
      else
      {
        if (arr[r - 1] == arr[r])
          l = r;
        else
        {
          l = r - 1;
          r--;
        }
        prv = "";
      }
      r++;
    }
    return res;
  }
};

int main()
{

  return 0;
}