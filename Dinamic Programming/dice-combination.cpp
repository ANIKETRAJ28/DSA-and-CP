#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;

// https://cses.fi/problemset/task/1633/

vector<int> dp;

// top-down
int ftd(int n){
    if(n == 0) return dp[n] = 1;

    if(dp[n] != -1) return dp[n];

    int ans = 0;

    for(int i = 1 ; i <= 6 ; i++){
        if(i > n) break;
        ans = ans % mod + ftd(n-i) % mod;
    }
    return dp[n] = ans % mod;

}

// bottom-up
int fbu(int n){
    dp.resize(1000005, 0);
    dp[0] = 1;

    for(int i = 1 ; i <= n ; i++){
        int ans = 0;
        for(int j = 1 ; j <= 6 ; j++){
            if(j > i) break;
             ans = ans % mod + dp[i-j] % mod;
        }
        dp[i] = ans % mod;
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    dp.clear();
    // dp.resize(1000005, -1);
    // cout<<ftd(n);
    cout<<fbu(n);
    return 0;
}