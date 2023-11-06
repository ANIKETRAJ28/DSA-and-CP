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
    string s = "EASY";
    while (n--)
    {
        int i;
        cin >> i;
        if (i == 1)
            s = "HARD";
    }
    cout << s;
    return 0;
}