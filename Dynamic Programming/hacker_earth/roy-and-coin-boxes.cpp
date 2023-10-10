#include <iostream>
#include <vector>
using namespace std;

// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/

int main()
{
    int n;
    cin >> n;
    vector<int> f(n + 1, 0);
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int L, R;
        cin >> L >> R;
        f[L]++;
        f[R + 1]--;
    }

    // making prefix sum
    for (int i = 1; i <= n; i++)
    {
        f[i] += f[i - 1];
    }

    // creating count array just like dp which will store the record of all occurances of i coin
    vector<int> c(10000005, 0);

    for (int i = 0; i <= n; i++)
    {
        int cnt = f[i];
        c[cnt]++;
    }

    // creating suffix sum
    for (int i = c.size() - 2; i >= 0; i--)
    {
        c[i] += c[i + 1];
    }

    // getting querries
    int q;
    cin >> q;
    while (q--)
    {
        int qr;
        cin >> qr;
        cout << c[qr] << endl;
    }

    return 0;
}