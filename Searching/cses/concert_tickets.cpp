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
    int n, m;
    cin >> n >> m;
    vec<int> tickets(n);
    vec<int> customer(m);
    for (int i = 0; i < n; i++)
    {
        cin >> tickets[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> customer[i];
    }
    sort(tickets.begin(), tickets.end());
    int i = 0, j = 0;
    vec<int> ans;
    while (i < n && j < m)
    {
        if (tickets[i] <= customer[j])
        {
            ans.push_back(customer[j]);
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    while (j < m)
    {
        ans.push_back(-1);
        j++;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}