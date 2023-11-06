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
    ll n;
    cin >> n;
    int cnt = 0;
    while (n)
    {
        if (n % 10 == 4 or n % 10 == 7)
            cnt++;
        n /= 10;
    }
    if (cnt == 4 or cnt == 7)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}