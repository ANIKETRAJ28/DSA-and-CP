#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

void solve(string &s)
{
    int n = s.size();
    stack<char> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i]);
        }
        else
        {
            char a = st.top();
            st.pop();
            char b = st.top();
            st.pop();
            st.push('(' + a + s[i] + b + ')');
        }
    }

    cout << st.top();
}

int main()
{

    return 0;
}