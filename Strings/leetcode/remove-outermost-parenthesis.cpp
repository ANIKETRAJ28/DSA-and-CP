#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/remove-outermost-parentheses/description/

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int close = 0, open = 0;
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            if(!open){
                open++;
                continue;
            }
            if(s[i] == '(') open++;
            else close++;
            if(open == close and s[i] == ')'){
                open = 0;
                close = 0;
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};

int main(){
    
    return 0;
}