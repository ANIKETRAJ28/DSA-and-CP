#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/alternating-groups-ii/description/

class Solution
{
public:
  int numberOfAlternatingGroups(vector<int> &colors, int k)
  {
    int n = colors.size();
    int i = 0, j = 1;
    int cnt = 0;
    while (j < n)
    {
      if (colors[j] == colors[j - 1])
        i = j;
      if (j - i + 1 == k)
        cnt++;
      while (i <= j && j - i + 1 >= k)
        i++;
      j++;
    }
    if (colors[0] == colors[n - 1])
      return cnt;
    i = 1;
    j = n - 2;
    for (i; i < k - 1; i++)
    {
      if (colors[i] == colors[i - 1])
        break;
    }
    i--;
    int c = k - i - 2;
    for (c; c > 0; c--, j--)
    {
      if (colors[j] == colors[j + 1])
        return cnt;
    }
    for (i; i >= 0; i--)
    {
      cnt++;
      if (colors[j] == colors[j + 1])
        return cnt;
      j--;
    }
    return cnt;
  }
};

int main()
{

  return 0;
}