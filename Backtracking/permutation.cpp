#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

void f(string &s, int i)
{
    int n = s.size();
    if (i == n - 1)
    {
        cout << s << "\n";
        return;
    }
    unordered_set<char> st;
    for (int idx = i; idx < n; idx++)
    {
        if (st.count(s[idx]))
            continue;
        st.insert(s[idx]);
        swap(s[i], s[idx]);
        f(s, i + 1);
        swap(s[i], s[idx]);
    }
}

int main()
{
    string s = "abba";
    f(s, 0);
    return 0;
}