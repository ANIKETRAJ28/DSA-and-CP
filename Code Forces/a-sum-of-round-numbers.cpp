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
    int x;
    cin >> x;
    while (x--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        int sumCnt = 0;
        vector<int> v;
        while (n != 0)
        {
            int num = n % 10;
            if (num == 0)
            {
                cnt++;
                n /= 10;
                continue;
            }
            int count = cnt;
            while (count--)
            {
                num *= 10;
            }
            v.push_back(num);
            sumCnt++;
            n /= 10;
            cnt++;
        }
        cout << sumCnt << "\n";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}