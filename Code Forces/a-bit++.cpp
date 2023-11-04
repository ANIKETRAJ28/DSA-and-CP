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
    int n;
    cin >> n;
    int cnt = 0;
    while (n--)
    {
        string s;
        cin >> s;
        if (s[1] == '+')
            cnt++;
        else
            cnt--;
    }
    cout << cnt;
    return 0;
}