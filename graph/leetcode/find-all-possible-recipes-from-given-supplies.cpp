#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/

class Solution
{
public:
  vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
  {
    int n = recipes.size();
    int m = supplies.size();
    unordered_map<string, vector<string>> graph;
    unordered_map<string, vector<string>> preparation;
    unordered_map<string, int> indegree;
    unordered_set<string> items;
    for (int i = 0; i < n; i++)
    {
      items.insert(recipes[i]);
      graph[recipes[i]] = {};
      indegree[recipes[i]] = 0;
      preparation[recipes[i]] = {};
      for (auto item : ingredients[i])
      {
        preparation[recipes[i]].push_back(item);
      }
    }
    for (int i = 0; i < n; i++)
    {
      string recipe = recipes[i];
      for (int j = 0; j < ingredients[i].size(); j++)
      {
        if (items.find(ingredients[i][j]) != items.end())
        {
          indegree[recipe]++;
          graph[ingredients[i][j]].push_back(recipe);
        }
      }
    }
    items.clear();
    for (int i = 0; i < m; i++)
    {
      items.insert(supplies[i]);
    }
    queue<string> qu;
    vector<string> result;
    for (auto it : indegree)
    {
      if (it.second == 0)
        qu.push(it.first);
    }
    while (!qu.empty())
    {
      string item = qu.front();
      qu.pop();
      bool flag = true;
      for (auto el : preparation[item])
      {
        if (items.find(el) == items.end())
        {
          flag = false;
          break;
        }
      }
      if (!flag)
        continue;
      result.push_back(item);
      items.insert(item);
      for (auto el : graph[item])
      {
        indegree[el]--;
        if (indegree[el] == 0)
        {
          indegree.erase(el);
          qu.push(el);
        }
      }
    }
    return result;
  }
};

int main()
{

  return 0;
}