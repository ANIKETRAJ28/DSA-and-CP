#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

int ftd(vec<int> &v, int i, int j)
{
    // base case
    if (i == j || i + 1 == j)
        return 0;
    int ans = infp;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, ftd(v, i, k) + ftd(v, k, j) + v[i] * v[k] * v[j]);
    }
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
    cout << ftd(v, 0, n - 1);
    return 0;
}