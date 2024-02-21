#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

ll dp[10005][10005];
// x -> as - cap i.e no. of assistant don't have captain
ll ftd(vec<ll> &cap, vec<ll> &as, int i, int x) {
    int n = cap.size();
    // base case
    if(i == n) return 0;
    if(dp[i][x] != -1) return dp[i][x];

    // x = 0 i.e every assistant got a captain, so next will be assistant
    if(x == 0) {
        return dp[i][x] = as[i] + ftd(cap, as, i+1, x+1);
    }
    // x == n-i (n = no. of crew member) i.e the remaining will be come captain as x is equal to remaining crew
    if(x == n-i) {
        return dp[i][x] = cap[i] + ftd(cap, as, i+1, x-1);
    }
    // we can pick cap or as
    return dp[i][x] = min(cap[i] + ftd(cap, as, i+1, x-1), as[i] + ftd(cap, as, i+1, x+1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    vec<ll> cap(n), as(n);
    for(int i = 0 ; i < n ; i++) {
        cin>>cap[i]>>as[i];
    }
    // first pilot will be assistant
    cout<<as[0]+ftd(cap, as, 1, 1);

    return 0;
}