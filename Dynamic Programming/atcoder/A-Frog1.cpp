#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://atcoder.jp/contests/dp/tasks/dp_a

vec<int> dp;

int jumps(vec<int> &k, int i) {
    // base case
    if(i == k.size()-1) return 0;
    if(i >= k.size()) return infp;
    if(dp[i] != -1) return dp[i];

    int sum = infp;
    sum = min(sum, abs(k[i] - k[i+1]) + jumps(k, i+1));
    if(i+2 < k.size()) sum = min(sum, abs(k[i] - k[i+2]) + jumps(k, i+2));
    
    return dp[i] = sum;
}

int main() {
    int n;
    cin>>n;
    vec<int> k(n);
    for(int i = 0 ; i < n ; i++) cin>>k[i];
    dp.resize(n+1, -1);
    cout<<jumps(k, 0);
    return 0;
}