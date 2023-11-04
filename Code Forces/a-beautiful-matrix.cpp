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
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int c;
            cin >> c;
            if (c == 1)
                cout << abs(i - 2) + abs(j - 2) << "\n";
        }
    }
    return 0;
}