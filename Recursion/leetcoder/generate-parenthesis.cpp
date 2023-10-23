#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/generate-parentheses/

class Solution
{
public:
    void generate(vector<string> &v, string s, int ob, int cb, int n)
    {
        if (ob == n && cb == n)
        {
            v.push_back(s);
            return;
        }
        if (ob <= n)
            generate(v, s + '(', ob + 1, cb, n);
        if (cb <= n && cb < ob)
            generate(v, s + ')', ob, cb + 1, n);
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> v;
        string s = "";
        generate(v, s, 0, 0, n);
        return v;
    }
};

int main()
{

    return 0;
}