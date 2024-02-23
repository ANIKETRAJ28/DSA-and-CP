#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.spoj.com/problems/ACODE/

vec<ll> dp;

ll ftd(string &str, int i) {
    // base case
    if(i <= 0) return 1;
    if(dp[i] != -1) return dp[i];
    ll ans = 0;
    if(str[i]-'0' > 0) {
        ans += ftd(str, i-1);
    }
    if(str[i-1] > '0' and (str[i-1]-'0')*10+(str[i]-'0') <= 26) {
        ans += ftd(str, i-2);
    }
    return dp[i] = ans;
}

ll fbu(string &str) {
    dp.clear();
    dp.resize(5005, 0);
    int n = str.size();
    if(str[0] != '0') dp[0] = 1;
    else dp[0] = 0;
    if(n > 1) {
        if(str[1] != '0') dp[1]++;
        if(str[0] != '0' and (str[0]-'0')*10+(str[1]-'0') <= 26) dp[1]++;
    }
    for(int i = 2 ; i < n ; i++) {
        ll ans = 0;
        if(str[i]-'0' > 0) {
            ans += dp[i-1];
        }
        if(str[i-1] > '0' and (str[i-1]-'0')*10+(str[i]-'0') <= 26) {
            ans += dp[i-2];
        }
        dp[i] = ans;
    }
    return dp[n-1];
}

int main() {
    string s;
    cin>>s;
    while(s[0] != '0') {
        // dp.clear();
        // dp.resize(5005, -1);
        // cout<<ftd(s, s.size()-1)<<"\n";
        cout<<fbu(s)<<"\n";
        cin>>s;
    }
    return 0;
}