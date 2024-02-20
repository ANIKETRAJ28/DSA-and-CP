#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

int dp[105][105][2];

int ftd(int n, int k, int last) {
    // base case
    if(n == 0) return 0;
    if(n == 1) {
        if(k == 0) return 1;
        return 0;
    }
    if(dp[n][k][last] != -1) return dp[n][k][last];

    if(last == 1) {
        return dp[n][k][last] = ftd(n-1, k-1, last) + ftd(n-1, k, 0);
    }
    return dp[n][k][last] = ftd(n-1, k, last) + ftd(n-1, k, 1);
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int num, n, k;
        cin>>num>>n>>k;
        memset(dp, -1, sizeof(dp));
        int ans = ftd(n, k, 1) + ftd(n, k, 0);
        cout<<num<<" "<<ans<<"\n"; 
    }
    return 0;
}