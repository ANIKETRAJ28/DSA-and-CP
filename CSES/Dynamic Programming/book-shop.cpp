#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

// https://cses.fi/problemset/task/1158

vector<vector<int>> dp;

// top-down TLE
ll ftd(vector<int> &prices, vector<int> &pages, int i, int amt){
    if(i >= prices.size()) return 0;
    if(dp[i][amt] != -1) return dp[i][amt];
    ll ans = 0;
    if(amt >= prices[i]) ans = pages[i] + ftd(prices, pages, i+1, amt-prices[i]);
    ans= max(ans, ftd(prices, pages, i+1, amt));
    return dp[i][amt] = ans;
}


int main(){
    int n, x;
    cin>>n>>x;
    vector<int> price(n), pages(n);
    for(int i = 0 ; i < n ; i++){
        cin>>price[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin>>pages[i];
    }
    // dp.resize(1005, vector<ll> (100005, -1));
    // cout<<ftd(prices,pages, 0, x);

    // bottom-up
    dp.resize(1005, vector<int> (100005, 0));
    // for price 0 no books can be bought and for 0 pages we cannot buy
    // so base case will be 0 for 0 price and 0 page
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= x ; j++) {
            if(j >= price[i-1]) dp[i][j] = max(dp[i-1][j], pages[i-1] + dp[i-1][j-price[i-1]]);
            else dp[i][j] = max(dp[i-1][j], dp[i][j]);
        }
    }
    cout<<dp[n][x]<<"\n";
    
    // for (int i = 0 ; i <= n ; i++) {
    //     for (int j = 0 ; j <= x ; j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}