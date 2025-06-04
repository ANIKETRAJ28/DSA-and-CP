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
    int dp[101];
    int f(string &s, int i)
    {
        int n = s.size();
        if (i == n)
            return 1;
        int ans = 0;
        if (s[i] != '0')
            ans += ftd(s, i + 1);
        if (i < n - 1 && s[i] != '0' && stoi(s.substr(i, 2)) <= 26)
            ans += ftd(s, i + 2);
        return ans;
    }
    int ftd(string &s, int i)
    {
        int n = s.size();
        if (i == n)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        int ans = 0;
        if (s[i] != '0')
            ans += ftd(s, i + 1);
        if (i < n - 1 && s[i] != '0' && stoi(s.substr(i, 2)) <= 26)
            ans += ftd(s, i + 2);
        return dp[i] = ans;
    }
    int fbu(string &s)
    {
        int n = s.size();
        memset(dp, 0, sizeof(dp));
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            int ans = 0;
            if (s[i] != '0')
                ans += dp[i + 1];
            if (i < n - 1 && s[i] != '0' && stoi(s.substr(i, 2)) <= 26)
                ans += dp[i + 2];
            dp[i] = ans;
        }
        return dp[0];
    }
    int fbuO(string &s)
    {
        int n = s.size();
        int first = 1;
        int last = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = 0;
            if (s[i] != '0')
            {
                curr += first;
                if (i < n - 1 && s[i] != '0' && stoi(s.substr(i, 2)) <= 26)
                    curr += last;
            }
            last = first;
            first = curr;
        }
        return first;
    }
    int numDecodings(string s)
    {
        // memset(dp, -1, sizeof(dp));
        // return ftd(s, 0);
        // return fbu(s);.
        return fbuO(s);
    }
};

int main()
{

    return 0;
}