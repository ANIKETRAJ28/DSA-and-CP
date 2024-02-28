#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

double dp[3005][3005];

double ftd(vec<double> &coins, int i, int diff) {
    if(diff == 0) return 1;
    if(i == -1) return 0;
    if(dp[i][diff] > -0.9) return dp[i][diff];

    return dp[i][diff] = ftd(coins, i-1, diff-1)*coins[i] + ftd(coins, i-1, diff)*(1 - coins[i]);
}

int main() {
    int n;
    cin>>n;
    vec<double> coins(n);
    memset(dp, -1, sizeof(dp));
    for(int i = 0 ; i < n ; i++) {
        cin>>coins[i];
    }
    cout<<fixed<<setprecision(9)<<ftd(coins, n-1, (n+1)/2);
    return 0;
}