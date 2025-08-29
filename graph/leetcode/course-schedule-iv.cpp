#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/course-schedule-iv/description/

class Solution
{
public:
  vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
  {
    int n = prerequisites.size();
    int m = queries.size();
    vector<int> indegree(numCourses, 0);
    vector<unordered_set<int>> outdegree(numCourses);
    vector<unordered_set<int>> dependencies(numCourses);
    for (int i = 0; i < n; i++)
    {
      int src = prerequisites[i][1];
      int dst = prerequisites[i][0];
      outdegree[dst].insert(src);
      indegree[src]++;
    }
    queue<int> qu;
    for (int i = 0; i < numCourses; i++)
    {
      if (indegree[i] == 0)
        qu.push(i);
    }
    while (!qu.empty())
    {
      int parent = qu.front();
      qu.pop();
      for (auto neig : outdegree[parent])
      {
        for (auto el : dependencies[parent])
        {
          dependencies[neig].insert(el);
        }
        indegree[neig]--;
        if (indegree[neig] == 0)
          qu.push(neig);
        dependencies[neig].insert(parent);
      }
    }
    vector<bool> result(m, 0);
    for (int i = 0; i < m; i++)
    {
      int src = queries[i][0];
      int dst = queries[i][1];
      if (dependencies[dst].find(src) != dependencies[dst].end())
        result[i] = true;
    }
    return result;
  }
};

int main()
{

  return 0;
}