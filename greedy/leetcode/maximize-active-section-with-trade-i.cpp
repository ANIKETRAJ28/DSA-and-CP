#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximize-active-section-with-trade-i/

class Solution
{
public:
  int maxActiveSectionsAfterTrade(string s)
  {
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '1')
        ans++;
    }
    int f_ans = ans;
    int i = 0;
    while (i < n)
    {
      if (s[i] == '1')
      {
        int strt1 = i;
        while (s[i] == '1')
          i++;
        int end1 = i - 1;
        if (strt1 == 0 || end1 == n - 1)
          continue;
        int preZeroCnt = 0, sufZeroCnt = 0;
        for (int j = strt1 - 1; j >= 0; j--)
        {
          if (s[j] == '0')
            preZeroCnt++;
          else
            break;
        }
        for (int j = end1 + 1; j < n; j++)
        {
          if (s[j] == '0')
            sufZeroCnt++;
          else
            break;
        }
        f_ans = max(f_ans, ans + preZeroCnt + sufZeroCnt);
      }
      i++;
    }
    return f_ans;
  }
};

int main()
{

  return 0;
}