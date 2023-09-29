#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define vec vector<ll>
#define vecvec vector<vector<ll>>
using namespace std;

// https://cses.fi/problemset/task/1746/

vecvec dp;
int n, m;
vector<int> arr; 

// top-down
ll ftd(int i, int x){
    if(i == 0||x == 0) return dp[i][x] = 0; 
    if(x > m) return dp[i][x] = 0; 

    if(i==1){
        if(arr[i] == x||arr[i] == 0)
        return dp[i][x] = 1;
        return dp[i][x] = 0;   
    }

    if(dp[i][x] != -1) return dp[i][x];
    ll cnt = 0;
    if(arr[i] == 0 || arr[i] == x){
        cnt = (ftd(i-1, x-1) % mod + ftd(i-1, x) % mod + ftd(i-1, x+1) % mod)% mod;
    }
    else return dp[i][x] = 0;
    return dp[i][x] = cnt;
}

int main(){
    cin>>n>>m;
    arr.clear();
    arr.resize(n+1);
    for(int i = 1 ; i <= n ; i++){
        cin>>arr[i];
    }
    dp.clear();
    // dp.resize(n+2, vec(m+2, -1));

    // ll ans = 0;
    // for(int i = 1 ; i <= m ; i++){
    //     ftd(n, i);
    // }
    // for(int i = 1 ; i <= m ; i++){
    //     ans = (ans % mod + dp[n][i]) % mod;
    // }
    // cout<<ans;

    // bottom up
    dp.resize(n+2, vec(m+2, 0));
    for(int i = 1 ; i <= n ; i++){
        // base case
        if(i == 1){
            if(arr[i] == 0){ // all choices
                for(int j = 1 ; j <= m ; j++){
                    dp[i][j] = 1;
                }
            }
            else{ // arr[i] != 0 and i == 1 so having 1 choice just the no. itself
                dp[i][arr[i]] = 1;
            }
        }
        else{
            if(arr[i] != 0){ // we have 3 choices from prev. ele the prev ele. having same val of j, j-1 and j+1
                dp[i][arr[i]] = (dp[i-1][arr[i]-1] % mod + dp[i-1][arr[i]] % mod) % mod;
                if(arr[i] != m) dp[i][arr[i]] = dp[i][arr[i]] % mod + dp[i-1][arr[i]+1] % mod; // if(arr[i] == m) 2 choices except m+1 out of bound
            }
            else{ // (arr[i] == 0) we have 3 choices 
                for(int j = 1 ; j <= m ; j++){
                    dp[i][j] = (dp[i-1][j-1] % mod + dp[i-1][j] % mod) % mod;
                    if(j != m) dp[i][j] = dp[i][j] % mod + dp[i-1][j+1] % mod; // if(arr[i] == m) 2 choices except m+1 out of bounarr[i]
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 1 ; i <= m ; i++){
        ans = (ans % mod + dp[n][i]) % mod;
    }

    cout<<ans<<"\n";

    // for(int i = 0 ; i <= m ; i++){
    //     for(int j = 0 ; j <= n ; j++){
    //         cout<<dp[j][i]<<" ";
    //     }
    //     cout<<"\n";
    // }

    return 0;
}