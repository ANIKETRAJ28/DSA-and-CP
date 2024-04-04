#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description

class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int ans = 0;
        int brac = 0;
        for(int i = 0 ; i < n ; i++) {
            if(s[i] == '(') brac++;
            if(s[i] == ')') brac--;
            ans = max(ans, brac);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}