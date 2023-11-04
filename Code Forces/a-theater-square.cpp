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
    ll n, m, a, len, wid;
    cin >> n >> m >> a;
    len = n / a + (n % a != 0);
    wid = m / a + (m % a != 0);
    cout << len * wid;
    return 0;
}