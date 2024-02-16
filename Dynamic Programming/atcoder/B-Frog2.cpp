#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://atcoder.jp/contests/dp/tasks/dp_b

vec<int> dp;

int jumps(vec<int> &k, int h, int i) {
    // base case
    if(i >= k.size()) return INT_MAX;
    if(i == k.size()-1) return 0;

    if(dp[i] != -1) return dp[i];
    int sum = INT_MAX;
    // calculating shortest path
    for(int j = 1 ; j <= h ; j++) {
        if(i+j >= k.size()) break;
        sum = min(sum, abs(k[i] - k[i+j])+ jumps(k, h, i+j));
    }
    return dp[i] = sum;
}

int main() {
    int n, h;
    cin>>n>>h;
    vec<int>k(n);
    for(int i = 0 ; i < n ; i++) cin>>k[i];
    dp.resize(n+1, -1);
    cout<<jumps(k, h, 0);
    return 0;
}