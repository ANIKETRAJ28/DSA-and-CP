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
    vec<int> desiredSize(n), appartments(m);
    for (int i = 0; i < n; i++)
    {
        cin >> desiredSize[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> appartments[i];
    }

    sort(desiredSize.begin(), desiredSize.end());
    sort(appartments.begin(), appartments.end());
    for (int i = 0; i < n; i++)
    {
        cout << desiredSize[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < m; i++)
    {
        cout << appartments[i] << " ";
    }
    cout << "\n";
    int i = 0, j = 0;
    int count = 0;
    while (i < m && j < n)
    {
        if (desiredSize[j] - k == appartments[i] || desiredSize[j] + k == appartments[i])
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