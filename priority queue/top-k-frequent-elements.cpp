#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    int n = nums.size();
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
      mp[nums[i]]++;
    for (auto el : mp)
    {
      if (pq.size() < k)
      {
        pq.push({el.second, el.first});
      }
      else if (pq.top().first < el.second)
      {
        pq.pop();
        pq.push({el.second, el.first});
      }
    }
    vector<int> ans;
    while (!pq.empty())
    {
      ans.push_back(pq.top().second);
      pq.pop();
    }
    return ans;
  }
};

int main()
{

  return 0;
}