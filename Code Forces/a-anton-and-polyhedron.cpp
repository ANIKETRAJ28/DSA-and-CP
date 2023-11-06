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
    int sum = 0;
    while (n--)
    {
        string s;
        cin >> s;
        if (s[0] == 'T')
            sum += 4;
        else if (s[0] == 'C')
            sum += 6;
        else if (s[0] == 'O')
            sum += 8;
        else if (s[0] == 'D')
            sum += 12;
        else
            sum += 20;
    }
    cout << sum;
    return 0;
}