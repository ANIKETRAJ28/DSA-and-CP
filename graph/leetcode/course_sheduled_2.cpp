#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/course-schedule-ii/

class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &pre)
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
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                qu.push(i);
            }
        }
        vector<int> ans;
        while (not qu.empty())
        {
            int node = qu.front();
            qu.pop();
            ans.push_back(node);
            for (int i = 0; i < graph[node].size(); i++)
            {
                int el = graph[node][i];
                indegree[el]--;
                if (indegree[el] == 0)
                {
                    qu.push(el);
                }
            }
        }
        vector<int> empty;
        return (ans.size() == n) ? ans : empty;
    }
};

int main()
{

    return 0;
}