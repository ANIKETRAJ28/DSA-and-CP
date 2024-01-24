#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    void f(int o, int c, string s, vector<string> &ans, int n) {
        if(o == n and c == n) {
            ans.push_back(s);
            return;
        }
        if(o > n or c > n) return;
        f(o+1, c, s+ '(', ans, n);
        if(c < o) f(o, c+1, s+ ')', ans, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(0, 0, "", ans, n);
        return ans;
    }
};


int main() {

    return 0;
}