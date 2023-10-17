#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://cses.fi/problemset/task/1621/

int main()
{
    int n;
    cin >> n;
    vec<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int count = 0;
    int check = infp;
    for (int i = 0; i < n; i++)
    {
        if (check != v[i])
            count++;
        check = v[i];
    }
    cout << count;
    return 0;
}