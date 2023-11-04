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
    vec<int> supply(8, 0);
    for (int i = 0; i < 8; i++)
    {
        cin >> supply[i];
    }
    int drink = (supply[1] * supply[2]) / supply[6];
    int lime = supply[4] * supply[3];
    int salt = supply[5] / supply[7];
    cout << min(drink, min(lime, salt)) / supply[0];
    return 0;
}