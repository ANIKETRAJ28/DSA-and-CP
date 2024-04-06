#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        int ob = 0, cb = 0;
        string ans = ""; 
        for(int i = n-1 ; i >= 0 ; i--) {
            if(s[i] == '(') {
                if(cb > ob) {
                    ob++;
                    ans += s[i];
                }
            } else {
                ans += s[i];
            }
            if(s[i] == ')') cb++;
        }
        ob = 0, cb = 0;
        s.clear();
        n = ans.size();
        for(int i = n-1 ; i >= 0 ; i--) {
            if(ans[i] == ')') {
                if(ob > cb) {
                    s += ans[i];
                    cb++;
                }
            } else {
                s += ans[i];
            }
            if(ans[i] == '(') ob++;
        }
        return s;
    }
};

int main() {
    
    return 0;
}