#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/number-of-provinces/description/

class Solution
{
public:
    void bfs(vector<vector<int>> &isConnected, int i, unordered_set<int> &visited)
    {
        int n = isConnected.size();
        queue<int> qu;
        qu.push(i);
        visited.insert(i);
        while (not qu.empty())
        {
            int el = qu.front();
            qu.pop();
            for (int j = 0; j < n; j++)
            {
                int ele = isConnected[el][j];
                if (not visited.count(j) and ele == 1)
                {
                    visited.insert(j);
                    qu.push(j);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        unordered_set<int> visited;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (not visited.count(i))
            {
                count++;
                bfs(isConnected, i, visited);
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}