#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/hand-of-straights/description/

class Solution
{
public:
  bool isNStraightHand(vector<int> &hand, int groupSize)
  {
    int n = hand.size();
    map<int, int> mp;
    for (int i : hand)
    {
      mp[i]++;
    }
    while (!mp.empty())
    {
      int cnt = 0;
      int prv = -1;
      for (auto it : mp)
      {
        int val = it.first;
        int freq = it.second;
        if (prv == -1)
        {
          prv = val;
        }
        else if (val != prv + 1)
        {
          return false;
        }
        prv = val;
        freq--;
        cnt++;
        if (freq == 0)
        {
          mp.erase(val);
        }
        else
        {
          mp[val] = freq;
        }
        if (cnt == groupSize)
        {
          break;
        }
      }
      if (cnt != groupSize)
        return false;
    }
    return true;
  }
};

int main()
{

  return 0;
}