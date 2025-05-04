#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/number-of-equivalent-domino-pairs/

class Solution
{
public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes)
  {
    int n = dominoes.size();
    map<pair<int, int>, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int a = dominoes[i][0];
      int b = dominoes[i][1];
      if (a == b)
        ans += mp[{a, b}];
      else
        ans += mp[{a, b}] + mp[{b, a}];
      mp[{a, b}]++;
    }
    return ans;
  }
};

class Solution
{
public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes)
  {
    int n = dominoes.size();
    unordered_map<int, vector<int>> mp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int a = dominoes[i][0];
      int b = dominoes[i][1];
      if (mp.find(a) == mp.end())
      {
        mp[a] = vector<int>(10, 0);
      }
      if (mp.find(b) == mp.end())
      {
        mp[b] = vector<int>(10, 0);
      }
      if (a == b)
        ans += mp[a][b];
      else
        ans += mp[a][b] + mp[b][a];
      mp[a][b]++;
    }
    return ans;
  }
};

int main()
{

  return 0;
}