#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/decode-ways/description/

class Solution
{
public:
    vector<int> dp;

    // top down
    ll ftd(string &s, int i)
    {
        if (i < 0)
            return 1;
        if (i == 0 && s[i] - '0' > 0)
            return 1;
        if (i == 0)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        ll ans = 0;

        if (s[i] - '0' > 0)
            ans += ftd(s, i - 1);

        if (s[i - 1] - '0' > 0 && (s[i - 1] - '0') * 10 + (s[i] - '0') <= 26)
            ans += ftd(s, i - 2);

        return dp[i] = ans;
    }

    // bottom up
    ll fbu(string &s)
    {
        dp.resize(105, 0);

        if (s[0] - '0' != 0)
            dp[0] = 1;
        if (s.size() > 1)
        {
            if (s[1] != '0')
                dp[1] += dp[0];
            if (s[0] - '0' > 0 && (s[0] - '0') * 10 + (s[1] - '0') <= 26)
                dp[1]++;
        }

        for (int i = 2; i < s.size(); i++)
        {
            ll ans = 0;

            if (s[i] - '0' > 0)
                ans += dp[i - 1];

            if (s[i - 1] - '0' > 0 && (s[i - 1] - '0') * 10 + (s[i] - '0') <= 26)
                ans += dp[i - 2];

            dp[i] = ans;
        }
        return dp[s.size() - 1];
    }

    int numDecodings(string s)
    {
        // dp.resize(105, -1);
        dp.clear();
        return fbu(s);
        // return ftd(s, s.size()-1);
    }
};

class Solution
{
public:
    vector<int> dp;
    int fbu(string &s)
    {
        int n = s.size();
        if (s[0] == '0')
            return 0;
        if (n == 1)
            return 1;
        dp[0] = 1;
        if (s[0] - '0' != 0 && ((s[0] - '0') * 10 + s[1] - '0') <= 26)
            dp[1] = 1;
        if (s[1] != '0')
            dp[1]++;
        for (int i = 2; i < n; i++)
        {
            if (s[i] - '0' > 0)
                dp[i] += dp[i - 1];
            if (s[i - 1] - '0' > 0 && ((s[i - 1] - '0') * 10 + s[i] - '0') <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[n - 1];
    }
    int numDecodings(string s)
    {
        dp.resize(105, 0);
        return fbu(s);
    }
};

int main()
{

    return 0;
}