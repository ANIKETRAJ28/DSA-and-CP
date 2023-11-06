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
    vec<int> line(n);
    int max = infn, maxidx = -1;
    int min = infp, minidx = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> line[i];
        if (max < line[i])
        {
            max = line[i];
            maxidx = i;
        }
        if (min >= line[i])
        {
            min = line[i];
            minidx = i;
        }
    }
    int res = 0;
    res += maxidx;
    if (maxidx > minidx)
        minidx++;
    res += (n - 1 - minidx);
    cout << res;
    return 0;
}