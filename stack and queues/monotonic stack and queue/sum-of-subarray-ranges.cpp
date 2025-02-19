#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/sum-of-subarray-ranges/description/

class Solution
{
public:
  long long subArrayRanges(vector<int> &arr)
  {
    int n = arr.size();
    long long mins = 0, maxs = 0;
    //         ele, idx
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && arr[i] < st.top().first)
      {
        pair<int, int> p = st.top();
        st.pop();
        long long lft = st.empty() == 1 ? p.second + 1 : p.second - st.top().second;
        long long rgt = i - p.second;
        long long res = lft * rgt;
        mins += res * p.first;
      }
      st.push({arr[i], i});
    }
    while (!st.empty())
    {
      pair<int, int> p = st.top();
      st.pop();
      long long lft = st.empty() == 1 ? p.second + 1 : p.second - st.top().second;
      long long rgt = n - p.second;
      long long res = lft * rgt;
      mins += res * p.first;
    }

    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && arr[i] > st.top().first)
      {
        pair<int, int> p = st.top();
        st.pop();
        long long lft = st.empty() == 1 ? p.second + 1 : p.second - st.top().second;
        long long rgt = i - p.second;
        long long res = lft * rgt;
        maxs += res * p.first;
      }
      st.push({arr[i], i});
    }
    while (!st.empty())
    {
      pair<int, int> p = st.top();
      st.pop();
      long long lft = st.empty() == 1 ? p.second + 1 : p.second - st.top().second;
      long long rgt = n - p.second;
      long long res = lft * rgt;
      maxs += res * p.first;
    }
    return maxs - mins;
  }
};

int main()
{

  return 0;
}