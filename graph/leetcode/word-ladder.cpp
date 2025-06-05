#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/word-ladder/

class Solution
{
public:
  bool check(string &s1, string &s2)
  {
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++)
    {
      if (s1[i] != s2[i])
        cnt++;
      if (cnt > 1)
        return false;
    }
    return true;
  }
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {
    int n = wordList.size();
    vector<list<int>> graph(n);
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (check(wordList[i], wordList[j]))
        {
          graph[i].push_back(j);
          graph[j].push_back(i);
        }
      }
    }
    queue<pair<int, int>> qu;
    unordered_set<int> vis;
    for (int i = 0; i < n; i++)
    {
      if (check(beginWord, wordList[i]))
      {
        qu.push({i, 2});
      }
    }
    while (!qu.empty())
    {
      int node = qu.front().first;
      int cnt = qu.front().second;
      vis.insert(node);
      if (endWord == wordList[node])
        return cnt;
      qu.pop();
      for (auto neig : graph[node])
      {
        if (!vis.count(neig))
        {
          qu.push({neig, cnt + 1});
        }
      }
    }
    return 0;
  }
};

int main()
{

  return 0;
}