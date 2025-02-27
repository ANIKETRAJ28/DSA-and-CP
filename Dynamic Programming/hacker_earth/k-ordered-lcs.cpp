#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

int dp[2005][2005][6];

int ftd(vec<int> &num1, vec<int> &num2, int i, int j, int k)
{
    // base case
    if (i >= num1.size() or j >= num2.size())
        return 0;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    // pick
    if (num1[i] == num2[j])
    {
        return dp[i][j][k] = 1 + ftd(num1, num2, i + 1, j + 1, k);
    }

    // not pick
    int res = 0;
    if (k > 0)
    {
        // pick
        res = 1 + ftd(num1, num2, i + 1, j + 1, k - 1);
    }
    res = max(res, ftd(num1, num2, i + 1, j, k));
    res = max(res, ftd(num1, num2, i, j + 1, k));

    return dp[i][j][k] = res;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vec<int> num1(n), num2(m);
    for (int i = 0; i < n; i++)
        cin >> num1[i];
    for (int i = 0; i < m; i++)
        cin >> num2[i];
    memset(dp, -1, sizeof(dp));
    cout << ftd(num1, num2, 0, 0, k);
    return 0;
}