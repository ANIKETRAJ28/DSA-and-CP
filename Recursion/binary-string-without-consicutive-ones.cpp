#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

void binaryString(vec<string> &vs, string s, int n)
{
    if (n == 0)
    {
        vs.push_back(s);
        return;
    }
    binaryString(vs, s + '0', n - 1);
    if (s == "" || s[s.size() - 1] == '0')
    {
        binaryString(vs, s + '1', n - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    vec<string> vs;
    binaryString(vs, "", n);
    for (int i = 0; i < vs.size(); i++)
    {
        string s = vs[i];
        for (int j = 0; j < s.size(); j++)
        {
            cout << s[j];
        }
        cout << "\n";
    }
    return 0;
}