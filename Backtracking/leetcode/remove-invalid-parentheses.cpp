#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/remove-invalid-parentheses/description/

class Solution
{
public:
    vector<string> ans;
    unordered_set<string> st, vis;
    int missing(string &s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '(' and s[i] != ')')
                continue;
            if (st.empty() or s[i] == '(')
            {
                st.push(s[i]);
                continue;
            }
            if (s[i] == ')')
            {
                if (st.top() == ')')
                    st.push(s[i]);
                else
                    st.pop();
            }
        }
        return st.size();
    }

    void f(string s, int cnt)
    {
        // base case
        if (vis.find(s) != vis.end())
            return;    // for removing redundant calls
        vis.insert(s); // for removing redundant calls
        if (cnt == 0 and st.find(s) == st.end())
        {
            st.insert(s);
            return;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ')' and s[i] != '(')
                continue;
            string concat = s.substr(0, i) + s.substr(i + 1);
            f(concat, cnt - 1);
        }
    }

    vector<string> removeInvalidParentheses(string s)
    {
        f(s, missing(s));
        for (auto el : st)
        {
            if (!missing(el))
                ans.push_back(el);
        }
        return ans;
    }
};

class Solution
{
public:
    void validStrings(unordered_set<string> &st, string &s, string &ans, int i, int o, int c)
    {
        int n = s.size();
        if (i == n)
        {
            if (o == c)
                st.insert(ans);
            return;
        }
        if (s[i] != ')' && s[i] != '(')
        {
            // push
            ans.push_back(s[i]);
            validStrings(st, s, ans, i + 1, o, c);
            // pop
            ans.pop_back();
        }
        else
        {
            // pick
            if (s[i] == '(')
            {
                ans.push_back(s[i]);
                validStrings(st, s, ans, i + 1, o + 1, c);
                // not pick
                ans.pop_back();
                validStrings(st, s, ans, i + 1, o, c);
            }
            else if (o > c)
            {
                ans.push_back(s[i]);
                validStrings(st, s, ans, i + 1, o, c + 1);
                // not pick
                ans.pop_back();
                validStrings(st, s, ans, i + 1, o, c);
            }
            else
            {
                validStrings(st, s, ans, i + 1, o, c);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s)
    {
        unordered_set<string> st;
        string ans = "";
        vector<string> f_ans;
        validStrings(st, s, ans, 0, 0, 0);
        int maxLen = 0;
        for (auto it = st.begin(); it != st.end(); it++)
        {
            string str = *it;
            int len = str.size();
            maxLen = max(maxLen, len);
        }
        for (auto it = st.begin(); it != st.end(); it++)
        {
            string str = *it;
            if (str.size() == maxLen)
            {
                f_ans.push_back(str);
            }
        }
        return f_ans;
    }
};

int main()
{

    return 0;
}