#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

int dp[2005][2005][10];

// https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/

int ftd(vec<int> &v1, vec<int> &v2, int i, int j, int k){
    int n = v1.size();
    int m = v2.size();
    // base case
    if(i == n || j == m || k == 0) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    int ans = infn;
    if(v1[i] == v2[j]) ans = max(ans, 1 + ftd(v1, v2, i+1, j+1, k));
    else{
        ans = max(ans, 1 + ftd(v1, v2, i+1, j+1, k-1));
        ans = max(ans, ftd(v1, v2, i+1, j, k));
        ans = max(ans, ftd(v1, v2, i, j+1, k));
    }
    return dp[i][j][k] = ans;
}

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vec<int> v1(n), v2(m);
    memset(dp, -1, sizeof(dp));
    for(int i = 0 ; i < n ; i++){
        cin>>v1[i];
    }
    for(int i = 0 ; i < m ; i++){
        cin>>v2[i];
    }
    cout<<ftd(v1, v2, 0, 0, k);
    return 0;
}