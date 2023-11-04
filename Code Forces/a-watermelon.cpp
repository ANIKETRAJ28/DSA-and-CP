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
    int w;
    cin >> w;
    if (w > 2 and w % 2 == 0)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}