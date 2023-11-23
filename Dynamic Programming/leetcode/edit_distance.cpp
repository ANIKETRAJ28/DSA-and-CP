#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/edit-distance/description/

class Solution
{
public:
    vector<vector<int>> dp;
    int f(string &s1, string &s2, int i, int j)
    {
        int n = s1.size();
        int m = s2.size();
        if (i == n and j == m)
        {
            return 0;
        }
        if (i == n)
        {
            return m - j;
        }
        if (j == m)
        {
            return n - i;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (s1[i] == s2[j])
            ans = f(s1, s2, i + 1, j + 1);
        else
        {
            ans = 1 + min({f(s1, s2, i + 1, j), f(s1, s2, i, j + 1), f(s1, s2, i + 1, j + 1)});
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2)
    {
        dp.resize(501, vector<int>(501, -1));
        return f(word1, word2, 0, 0);
    }
};

int main()
{

    return 0;
}