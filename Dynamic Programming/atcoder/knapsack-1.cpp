#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://atcoder.jp/contests/dp/tasks/dp_d

vec<vec<ll>> dp;

ll ftd(vec<int> &wts, vec<int> &val, int idx, int wt){
    int n = wts.size();
    if(dp[idx][wt] != -1) return dp[idx][wt];
    if(idx == n) return 0;
    ll ans = 0;
    // not-pick
    ans = max(ans, ftd(wts, val, idx+1, wt));
    // pick
    if(wts[idx] <=  wt){
        ans = max(ans, val[idx] + ftd(wts, val, idx+1, wt-wts[idx]));
    }
    return dp[idx][wt] = ans;
}

ll fbu(vec<int> &wts, vec<int> &val, int wt){
    // base case handled
    dp.resize(105, vec<ll> (100005, 0));
    int n = wts.size();
    for(int i = n-1 ; i >= 0 ; i--){
        for(int j = 0 ; j <= wt; j++){
            // not-pick
            dp[i][j] = dp[i+1][j];
            // pick
            if(wts[i] <= j){
                dp[i][j] = max(dp[i][j], val[i] + dp[i+1][j-wts[i]]);
            }
        }
    }
    return dp[0][wt];

}

int main(){
    int n, w;
    cin>>n>>w;
    vec<int> wts (n);
    vec<int> val (n);
    for(int i = 0 ; i < n ; i++){
        cin>>wts[i]>>val[i];
    }
    // dp.resize(105, vec<ll> (100005, -1));
    // cout<<ftd(wts, val, 0, w);
    cout<<fbu(wts, val, w);
    return 0;
}