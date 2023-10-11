#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

vec<vec<int>> dp;

int ftd(vector<int> &v, int i, int j)
{
    // base case
    if (i == j || i + 1 == j)
        return 0;
    // if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;

    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, ftd(v, i, k) + ftd(v, k, j) + v[i] * v[j] * v[k]);
    }
    // return dp[i][j] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vec<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    dp.resize(1005, vec<int>(1005, 0));
    // cout << ftd(v, 0, n - 1);
    //     int matrixChainMultiplication(vec<int> &dims)
    // {
    //     int n = dims.size();
    //     dp.resize(n, vec<int>(n, 0));

    //     for (int len = 2; len < n; len++)
    //     {
    //         for (int i = 1; i < n - len + 1; i++)
    //         {
    //             int j = i + len - 1;
    //             dp[i][j] = INT_MAX;

    //             for (int k = i; k < j; k++)
    //             {
    //                 dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j]);
    //             }
    //         }
    //     }

    //     return dp[1][n - 1];
    // }
    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + v[i - 1] * v[k] * v[j]);
            }
        }
    }
    cout << dp[1][n - 1] << "\n";
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}