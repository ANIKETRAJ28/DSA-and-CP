#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

// https://cses.fi/problemset/task/1635

vector<ll> dp;

// top-down
ll ftd(vector<ll> &v, ll sum){
    if(sum == 0) return 1;
    if(dp[sum] != -1) return dp[sum];
    int n = v.size();
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        if(v[i] > sum) break;
        ans += ftd(v, sum-v[i]) % mod;
    }
    return dp[sum] = ans % mod;
}


int main(){
    int n;
    cin>>n;
    ll sum;
    cin>>sum;
    vector<ll> v(n);
    dp.clear();
    // dp.resize(1000005, -1);
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    // cout<<ftd(v, sum);
    // bottom-up
    dp.resize(1000005, 0);
    dp[0] = 1; // base case
    for(int i = 1 ; i <= sum ; i++){
        for(int j = 0 ; j < n ; j++){
            if(v[j] > i) break;
            dp[i] = (dp[i] + dp[i - v[j]])%mod;
        }
    }
    cout<<dp[sum];
    return 0;
}