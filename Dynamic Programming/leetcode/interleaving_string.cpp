#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/interleaving-string/description/

class Solution
{
public:
    int dp[101][101];
    bool f(string &s1, string &s2, string &s3, int i, int j, int k)
    {
        int n = s1.size();
        int m = s2.size();
        int l = s3.size();
        if (i == n and j == m)
            return dp[i][j] = true;
        if (i == n)
        {
            if (s3[k] != s2[j])
                return dp[i][j] = false;
            return dp[i][j] = f(s1, s2, s3, i, j + 1, k + 1);
        }
        if (j == m)
        {
            if (s3[k] != s1[i])
                return dp[i][j] = false;
            return dp[i][j] = f(s1, s2, s3, i + 1, j, k + 1);
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s3[k] and s2[j] == s3[k])
        {
            return dp[i][j] = (f(s1, s2, s3, i + 1, j, k + 1) or f(s1, s2, s3, i, j + 1, k + 1));
        }
        if (s1[i] == s3[k])
            return dp[i][j] = f(s1, s2, s3, i + 1, j, k + 1);
        else if (s2[j] == s3[k])
            return dp[i][j] = f(s1, s2, s3, i, j + 1, k + 1);
        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;
        memset(dp, -1, sizeof(dp));
        return f(s1, s2, s3, 0, 0, 0);
    }
};

int main()
{

    return 0;
}