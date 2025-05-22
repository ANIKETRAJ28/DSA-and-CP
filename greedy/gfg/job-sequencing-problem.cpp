#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

class Solution
{
public:
  vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
  {
    // code here
    int n = profit.size();
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
      v[i] = {deadline[i], profit[i]};
    }
    sort(v.begin(), v.end());
    int ans = 0, cnt = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
      int d = v[i].first;
      int p = v[i].second;
      if (d > cnt)
      {
        pq.push(p);
        cnt++;
        ans += p;
      }
      else
      {
        ans -= pq.top();
        pq.pop();
        pq.push(p);
        ans += p;
      }
    }

    return {cnt, ans};
  }
};

int main()
{

  return 0;
}