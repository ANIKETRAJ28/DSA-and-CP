#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/sum-of-subarray-minimums/description/

class Solution
{
public:
  vector<int> prvSmaller(vector<int> &arr)
  {
    int n = arr.size();
    stack<int> st;
    vector<int> prv(n);
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && arr[st.top()] > arr[i])
        st.pop();
      prv[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }
    return prv;
  }
  vector<int> nxtSmaller(vector<int> &arr)
  {
    int n = arr.size();
    stack<int> st;
    vector<int> nxt(n);
    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && arr[st.top()] >= arr[i])
        st.pop();
      nxt[i] = st.empty() ? n : st.top();
      st.push(i);
    }
    return nxt;
  }
  int sumSubarrayMins(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> prv = prvSmaller(arr);
    vector<int> nxt = nxtSmaller(arr);
    int MOD = 1e9 + 7;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int prev = i - prv[i];
      int next = nxt[i] - i;
      int total = (1LL * prev * next) % MOD;
      ans = (ans + (1LL * total * arr[i]) % MOD) % MOD;
    }
    return ans;
  }
};

class Solution
#define mod 1000000007
{
public:
  int sumSubarrayMins(vector<int> &arr)
  {
    int n = arr.size();
    long ans = 0;
    //         ele, idx
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && arr[i] < st.top().first)
      {
        pair<int, int> p = st.top();
        st.pop();
        int lft = st.empty() == 1 ? p.second + 1 : p.second - st.top().second;
        int rgt = i - p.second;
        long res = lft * rgt % mod;
        ans += (res * p.first) % mod;
        ans %= mod;
      }
      st.push({arr[i], i});
    }
    while (!st.empty())
    {
      pair<int, int> p = st.top();
      st.pop();
      long lft = st.empty() == 1 ? p.second + 1 : p.second - st.top().second;
      long rgt = n - p.second;
      long res = lft * rgt % mod;
      ans += (res * p.first) % mod;
      ans %= mod;
    }
    return (int)ans;
  }
};

int main()
{

  return 0;
}