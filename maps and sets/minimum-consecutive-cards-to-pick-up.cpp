#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/

class Solution
{
public:
  int minimumCardPickup(vector<int> &cards)
  {
    int n = cards.size();
    int ans = INT_MAX;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      int ele = cards[i];
      if (mp.find(ele) == mp.end())
      {
        mp[ele] = i;
        continue;
      }
      else
      {
        if (i - mp[ele] + 1 < ans)
          ans = i - mp[ele] + 1;
        mp[ele] = i;
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};

int main()
{

  return 0;
}