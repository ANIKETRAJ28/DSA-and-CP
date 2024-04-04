#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '(') {
                st.push(s[i]);
            }
            else if(s[i] == '{') {
                st.push(s[i]);
            }
            else if(s[i] == '[') {
                st.push(s[i]);
            }
            else if(s[i] == ')') {
                if(st.empty()) return false;
                if(st.top() == '(') st.pop();
                else return false;
            }
            else if(s[i] == '}') {
                if(st.empty()) return false;
                if(st.top() == '{') st.pop();
                else return false;
            }
            else if(s[i] == ']') {
                if(st.empty()) return false;
                if(st.top() == '[') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};

int main() {
    
    return 0;
}