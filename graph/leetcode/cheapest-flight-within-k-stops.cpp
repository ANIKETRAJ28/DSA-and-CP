#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<list<pp>> graph(n, list<pp>());
        for (int i = 0; i < flights.size(); i++)
        {
            graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        queue<pp> qu;
        qu.push({src, 0});
        vector<int> ans(n, INT_MAX);
        ans[src] = 0;
        while (not qu.empty() and k >= 0)
        {
            int n = qu.size();
            while (n--)
            {
                pp el = qu.front();
                qu.pop();
                for (auto neig : graph[el.first])
                {
                    if (ans[neig.first] > neig.second + el.second)
                    {
                        ans[neig.first] = neig.second + el.second;
                        qu.push({neig.first, ans[neig.first]});
                    }
                }
            }
            k--;
        }
        return (ans[dst] == INT_MAX) ? -1 : ans[dst];
    }
};

int main()
{

    return 0;
}