#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/remove-invalid-parentheses/description/

class Solution {
public:
    vector<string> ans;
    unordered_set<string> st, vis;
    int missing(string &s) {
        stack<char> st;
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] != '(' and s[i] != ')') continue;
            if(st.empty() or s[i] == '(') {
                st.push(s[i]);
                continue;
            }
            if(s[i] == ')') {
                if(st.top() == ')') st.push(s[i]);
                else st.pop();
            }
        }
        return st.size();
    }

    void f(string s, int cnt) {
        // base case
        if(vis.find(s) != vis.end()) return; // for removing redundant calls
        vis.insert(s); //for removing redundant calls
        if(cnt == 0 and st.find(s) == st.end()) {
            st.insert(s);
            return;
        }
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] != ')' and s[i] != '(') continue;
            string concat = s.substr(0, i) + s.substr(i+1);
            f(concat, cnt-1);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        f(s, missing(s));
        for(auto el : st) {
            if(!missing(el)) ans.push_back(el);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}