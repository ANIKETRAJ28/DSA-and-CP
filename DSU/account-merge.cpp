#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://www.geeksforgeeks.org/problems/account-merge/1

class Solution
{
public:
  vector<int> parent;
  vector<set<string>> rank;
  int find(int i)
  {
    return parent[i] = parent[i] == i ? i : find(parent[i]);
  }
  void Union(int i, int j)
  {
    i = parent[i];
    j = parent[j];
    if (i == j)
      return;
    if (rank[j].size() > rank[i].size())
      swap(i, j);
    for (auto el1 : rank[i])
    {
      if (rank[j].find(el1) != rank[j].end())
      {
        for (auto el2 : rank[j])
        {
          rank[i].insert(el2);
        }
        rank[j].clear();
        parent[j] = i;
        break;
      }
    }
    return;
  }
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
  {
    // code here
    int n = accounts.size();
    parent.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
      set<string> st;
      for (int j = 1; j < accounts[i].size(); j++)
      {
        st.insert(accounts[i][j]);
      }
      rank[i] = st;
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (accounts[i][0] == accounts[j][0])
          Union(i, j);
      }
    }
    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
      if (parent[i] == i)
      {
        vector<string> v;
        v.push_back(accounts[i][0]);
        for (auto el : rank[i])
        {
          v.push_back(el);
        }
        ans.push_back(v);
      }
    }
    return ans;
  }
};

int main()
{

  return 0;
}