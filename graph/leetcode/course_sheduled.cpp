#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/course-schedule/

class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &pre)
    {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for (int i = 0; i < pre.size(); i++)
        {
            int src = pre[i][1];
            int dst = pre[i][0];
            graph[src].push_back(dst);
            indegree[dst]++;
        }
        queue<int> qu;
        unordered_set<int> visited;
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                qu.push(i);
                visited.insert(i);
            }
        }
        while (not qu.empty())
        {
            int node = qu.front();
            qu.pop();
            for (int i = 0; i < graph[node].size(); i++)
            {
                int newNode = graph[node][i];
                if (not visited.count(newNode))
                {
                    indegree[newNode]--;
                    if (indegree[newNode] == 0)
                    {
                        qu.push(newNode);
                        visited.insert(newNode);
                    }
                }
            }
        }
        return n == visited.size();
    }
};

int main()
{

    return 0;
}