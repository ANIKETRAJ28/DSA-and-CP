#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

// https://cses.fi/problemset/task/1158

vector<vector<ll>> dp;

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
    vector<int> prices;
    for(int i = 0 ; i < n ; i++){
        int price;
        cin>>price;
        prices.push_back(price);
    }
    vector<int> pages;
    for(int i = 0 ; i < n ; i++){
        int page;
        cin>>page;
        pages.push_back(page);
    }
    dp.resize(1005, vector<ll> (100005, -1));
    cout<<ftd(prices,pages, 0, x);
    return 0;
}