#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://cses.fi/problemset/task/1090/

int main()
{
    int n, wt;
    cin >> n >> wt;
    vec<int> children(n);
    for (int i = 0; i < n; i++)
    {
        cin >> children[i];
    }
    sort(children.begin(), children.end());
    int i = 0, j = n - 1;
    int count = 0;
    while (i <= j)
    {
        if (i != j)
        {
            if (children[i] + children[j] <= wt)
            {
                count++;
                i++;
                j--;
            }
            else
            {
                j--;
                count++;
            }
        }
        else
        {
            count++;
            i++;
            j--;
        }
    }
    cout << count;
    return 0;
}