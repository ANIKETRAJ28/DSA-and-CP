#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define vec vector<ll>
#define vecvec vector<vector<ll>>
using namespace std;

vecvec dp;

ll ftd(vector<int> &arr, int i, int j){
    // base case
    if(j == i) return arr[i];
    if(j < i) return 0;
    if(j-i == 1) return max(arr[i], arr[j]);
    if(dp[i][j] != -1) return dp[i][j];

    ll ans = 0;
    // if a takes ith idx then b will try to take the value by which a gets minimum
    // if a takes jth idx then b will try to take the value by which a gets minimum
    // the final result will be max(taking ith index val, taking jth index val)
    ans = max(min(arr[i] + ftd(arr, i+2, j), arr[i] +  ftd(arr, i+1, j-1)), min(arr[j] +  ftd(arr, i, j-2), arr[j] +  ftd(arr, i+1, j-1)));
    return dp[i][j] = ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    dp.clear();
    dp.resize(5005, vec(5005, -1));
    cout<<ftd(arr, 0, n-1);
    return 0;
}