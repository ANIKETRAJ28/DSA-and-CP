#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

// https://cses.fi/problemset/task/1634

vector<int> dp;

// top-down
int ftd(vector<int> &v, int sum){
    if(sum == 0) return 0;
    if(dp[sum] != -1) return dp[sum];
    int n = v.size();
    int ans = INT_MAX;
    for(int i = 0 ; i < n ; i++){
        if(sum < v[i]) continue;
        ans = min(ans, ftd(v, sum - v[i]));
    }
    if(ans == INT_MAX) return dp[sum] = INT_MAX;
    return dp[sum] = 1 + ans;
}

int main(){
    int n;
    cin>>n;
    int sum;
    cin>>sum;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
    }
    // dp.clear();
    // dp.resize(1000005, -1);
    // int res = ftd(v, sum);
    // (res == INT_MAX) ? cout<<-1 : cout<<res;
    // bottom-up
    dp.clear();
    dp.resize(sum+1, INT_MAX);
    dp[0] = 0;
    for(int t = 1 ; t <= sum ; t++) {
        for(int i = 0 ; i  < n ; i++) {
            if(v[i] > t) continue;
            dp[t] = min(dp[t], 1 + dp[t - v[i]]);
        }
    }
    if(dp[sum] == INT_MAX) cout<<-1;
    else cout<<dp[sum];
    return 0; 
}