#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

// https://cses.fi/problemset/task/1636

vector<ll> dp;
// vector<vector<ll>> dp1;

// top-down // TLE
// ll ftd(vector<ll> &v, int i, ll sum){
//     int n = v.size();
//     if(sum < 0 || i >= n) return 0;
//     if(sum == 0) return 1;
//     if(dp1[i][sum] != -1) return dp1[i][sum];
//     return dp1[i][sum] = (ftd(v,i,sum-v[i])%mod+ftd(v,i+1,sum)%mod)%mod;
// }

int main(){
    int n;
    cin>>n;
    ll sum;
    cin>>sum;
    vector<ll> v(n);
    dp.clear();
    // dp1.clear();
    // dp1.resize(n+1, vector<ll>(sum+1, -1));
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
    }
    // sort(v.begin(), v.end());
    // cout<<ftd(v, 0, sum); // TLE
    // bottom-up
    dp.resize(1000005, 0);
    dp[0] = 1; // base case
    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j <= sum ; j++){
            if(v[i] > j) continue;
            dp[j] = (dp[j] + dp[j-v[i]]) % mod;
        }
    }
    cout<<dp[sum];
    return 0;
}