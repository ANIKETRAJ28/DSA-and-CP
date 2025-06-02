#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/unique-binary-search-trees/description/

class Solution
{
public:
    vector<int> dp;
    int f(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += f(i - 1) * f(n - i);
        }
        return ans;
    }
    int ftd(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += ftd(i - 1) * ftd(n - i);
        }
        return dp[n] = ans;
    }
    int fbu(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        dp.resize(20, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int ans = 0;
            for (int j = 1; j <= i; j++)
            {
                ans += dp[j - 1] * dp[i - j];
            }
            dp[i] = ans;
        }
        return dp[n];
    }
    int numTrees(int n)
    {
        // return f(n);
        // dp.resize(20, -1);
        // return ftd(n);
        return fbu(n);
    }
};

int main()
{

    return 0;
}