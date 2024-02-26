#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

vec<ll> colors;
int dp[105][105];

ll g(int i, int j) {
    ll res = 0;
    for(int k = i ; k <= j ; k++) {
        res = (res % 100 + colors[k] % 100) % 100;
    }
    return res;
}

ll ftd(int i, int j) {
    // base case
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    ll res = infp;
    for(int k = i ; k < j ; k++) {
        res = min(res, ftd(i, k) + ftd(k+1, j) + g(i, k) * g(k+1, j));
    }
    return dp[i][j] = res;
}

int main() {
    int m;
    while(cin>>m) {
        for(int i = 0 ; i < m ; i++) {
            int k;
            cin>>k;
            colors.push_back(k);
        }
        memset(dp, -1, sizeof dp);
        cout<<ftd(0, colors.size()-1)<<"\n";
        colors.clear();
    }
    return 0;
}