#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://atcoder.jp/contests/dp/tasks/dp_f

int main() {
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.size(), m = s2.size();
    vec<vec<ll>> dp;
    dp.resize(n+1, vec<ll>(m+1, 0));
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= m ; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    string ans = "";
    int i = n, j = m;
    while(i > 0 and j > 0) {
        if(s1[i-1] == s2[j-1]) {
            ans += s1[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else j--;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<"\n";
    return 0;
}