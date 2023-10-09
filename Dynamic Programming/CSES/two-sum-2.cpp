#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://cses.fi/problemset/task/1093

vec<vec<ll>> dp;

ll ftd(vec<int> &v, int i, int sum){
    // base case
    int n = v.size();
    if(sum < 0) return 0;
    if(sum == 0) return 1;
    if(sum < v[i] || i == n) return 0;
    if(dp[i][sum] != -1) return dp[i][sum];
    return dp[i][sum] = ftd(v, i+1, sum) % mod + ftd(v, i+1, sum - v[i]) % mod;
}

int main(){
    int n;
    cin>>n;
    vec<int> v(n);
    ll sum = (n*(n+1));
    sum /= 2;
    dp.resize(n+1, vec<ll>(70000, -1));
    for(int i = 0 ; i < n ; i++){
        v[i] = i+1;
    }
    if(sum % 2 != 0){
        cout<<0;
        return 0;
    }
    cout<<ftd(v, 0, sum/2)/2;
    return 0;
}