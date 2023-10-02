#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define vec vector<ll>
#define vecvec vector<vector<ll>>
using namespace std;

vector<vector<int>> dp;

// top-down
int ftd(int a, int b){
    // base case
    if(a == b) return 0;
    if(a == 1) return b-1;
    if(b == 1) return a-1;
    if(b > a) swap(a, b); // to avoide TLE
    if(dp[a][b] != -1) return dp[a][b];

    int ans = INT_MAX;

    for(int i = 1 ; i < b ; i++){
        ans = min(ans, 1 + ftd(a, i) + ftd(a, b-i));
    }
    for(int i = 1 ; i < a ; i++){
        ans = min(ans, 1 + ftd(i, b) + ftd(a-i, b));
    }   
    return dp[a][b] = ans;
}

int main(){
    int a, b;
    cin>>a>>b;
    // dp.resize(505, vector<int> (505, -1));
    // cout<<ftd(a, b);
    
    // bottom-up
    dp.resize(505, vector<int> (505, INT_MAX));

    for(int i = 1 ; i <= a ; i++){
        for(int j = 1 ; j <= b ; j++){
            if(i == j) dp[i][j] = 0;
            else{
                // vertical cut
                for(int k = 1 ; k < j ; k++){
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
                }
                // horizontal cut
                for(int k = 1 ; k < i ; k++){
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
                }
            }
        }
    }
    cout<<dp[a][b]<<"\n";
    // for(int i = 1 ; i <= a ; i++){
    //     for(int j = 1 ; j <= b ; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}