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
    if (n % groupSize)
      return false;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      if (mp.find(hand[i]) == mp.end())
      {
        pq.push(hand[i]);
      }
      mp[hand[i]]++;
    }
    while (!pq.empty())
    {
      int val = pq.top();
      mp[val]--;
      if (mp[val] == 0)
      {
        pq.pop();
        mp.erase(val);
      }
      int cnt = 1;
      val++;
      while (cnt < groupSize)
      {
        if (mp.find(val) == mp.end())
          return false;
        mp[val]--;
        if (mp[val] == 0)
        {
          mp.erase(val);
          if (pq.top() != val)
            return false;
          pq.pop();
        }
        val++;
        cnt++;
      }
    }
    return true;
  }
};

int main()
{

  return 0;
}