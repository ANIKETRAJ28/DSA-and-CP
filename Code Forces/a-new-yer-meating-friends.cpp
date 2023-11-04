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
    vector<int> arr(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << arr[2] - arr[1] + arr[1] - arr[0];
    return 0;
}