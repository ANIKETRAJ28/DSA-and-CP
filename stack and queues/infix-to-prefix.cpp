#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

int priority(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void solve(string &s)
{
    int n = s.size();
    string output = "";
    stack<char> st;

    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
        {
            s[i] = '(';
        }
        else if (s[i] == '(')
        {
            s[i] = ')';
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
        {
            output += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                output += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (s[i] == '^')
            {
                while (!st.empty() && priority(s[i]) <= priority(st.top()))
                {
                    output += st.top();
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && priority(s[i]) < priority(st.top()))
                {
                    output += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        output += st.top();
        st.pop();
    }

    reverse(output.begin(), output.end());

    cout << output << endl;
}

int main()
{

    return 0;
}