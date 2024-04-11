#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/remove-k-digits/description

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == n) return "0";
        int del = 0;
        string ans = "";
        ans += num[0];
        for(int i = 1 ; i < n ; i++) {
            while(ans.size() > 0  && del < k && num[i] < ans[ans.size()-1]) {
                ans.pop_back();
                del++;
            }
            ans += num[i];
        }
        int j = 0;
        while(ans[j] == '0') j++;
        ans = ans.substr(j);
        if(del == 0) return ans.substr(0, ans.size()-k);
        while(ans.size() > 0 && del++ < k) ans.pop_back();
        return ans.size() == 0 ? "0" : ans;
    }
};

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == n) return "0";
        stack<char> st;
        st.push(num[0]);
        int del = 0;
        for(int i = 1 ; i < n ; i++) {
            while(!st.empty() && num[i] < st.top() && del++ < k) st.pop();
            st.push(num[i]);
        }
        num.clear();
        while(!st.empty()) {
            num += st.top();
            st.pop();
        }
        reverse(num.begin(), num.end());
        n = num.size();
        int j = 0;
        while(num[j] == '0') j++;
        num = num.substr(j);
        if(del == 0) return num.substr(0, n-k);
        while(del++ < k && num.size() > 0) num.pop_back();
        return num.size() == 0 ? "0" : num;
    }
};

int main() {
    
    return 0;
}