#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

// https://cses.fi/problemset/task/1637

vector<ll> dp;

vector<int> digits(int n){
    vector<int> digit;
    while(n != 0){
        digit.push_back(n%10);
        n /= 10;
    }
    return digit;
}

// top-down
ll ftd(int n) {
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    vector<int> digit = digits(n);
    ll ans = INT_MAX;

    for(int i = 0 ; i < digit.size() ; i++){
        if(digit[i] != 0) ans = min(ans, ftd(n-digit[i]));
    }

    return dp[n] = 1 + ans;
}

int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(1000005, -1);
    // cout<<ftd(n);

    // bottom-up
    dp[0] = 0; // base case
    for(int i = 1 ; i <= 9 ; i++){ // base case
        dp[i] = 1;
    }

    for(int i = 10 ; i <= n ; i++){
        vector<int> digit = digits(i);
        ll ans = INT_MAX;
        for(int j = 0 ; j < digit.size() ; j++){
            if(digit[j] != 0) ans = min(ans, dp[i-digit[j]]);
        }
        dp[i] = 1 + ans;
    }

    cout<<dp[n];
    return 0;
}