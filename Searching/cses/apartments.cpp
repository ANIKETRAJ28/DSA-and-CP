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
    int n, m, k;
    cin >> n >> m >> k;
    vec<int> applicants(n), appartments(m);
    for (int i = 0; i < m; i++)
    {
        cin >> appartments[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> applicants[i];
    }

    sort(applicants.begin(), applicants.end());
    sort(appartments.begin(), appartments.end());
    int i = 0, j = 0;
    int count = 0;
    while (i <= m && j <= n)
    {
        if (appartments[j] >= applicants[i] || appartments[j] >= applicants[i] - k)
        {
            i++;
            j++;
            count++;
        }
        else
        {
            j++;
        }
    }
    cout << count;
    return 0;
}