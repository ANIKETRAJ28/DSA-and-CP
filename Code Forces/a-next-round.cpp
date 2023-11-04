#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

int main()
{
    int n, k;
    cin >> n >> k;
    vec<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        // v[k] == 0
        // v[k] > 0
        if (v[k] == 0)
        {
            if (v[i] > v[k])
                cnt++;
        }
        else
        {
            if (v[i] >= v[k])
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}