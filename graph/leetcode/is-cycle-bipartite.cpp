#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/is-graph-bipartite/

class Solution
{
public:
    bool bfs(vector<vector<int>> &graph, vector<int> &color, unordered_set<int> &visited, int src)
    {
        int n = graph.size();
        queue<int> qu;
        qu.push(src);
        color[src] = 1; // red
        while (not qu.empty())
        {
            int el = qu.front();
            qu.pop();
            visited.insert(el);
            for (int i = 0; i < graph[el].size(); i++)
            {
                if (color[graph[el][i]] != color[el])
                {
                    color[graph[el][i]] = color[el] * -1;
                    if (not visited.count(graph[el][i]))
                        qu.push(graph[el][i]);
                }
                else
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, 0);
        unordered_set<int> visited;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == 0)
            {
                if (not bfs(graph, color, visited, i))
                    return false;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}