#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define vec vector<ll>
#define vecvec vector<vector<ll>>
using namespace std;
// https://cses.fi/problemset/task/1639

vecvec dp;

int ftd(string &s1, string &s2, int i, int j){
    // base case
    if(i == 0) return dp[i][j] = j;
    if(j == 0) return dp[i][j] = i;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i-1] == s2[j-1]) return dp[i][j] = ftd(s1, s2, i-1, j-1);
    else{
        return dp[i][j] = 1 + min({ftd(s1, s2, i-1, j-1), ftd(s1, s2, i-1, j), ftd(s1, s2, i, j-1)});
    }
}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    // dp.resize(5005, vec(5005, -1));
    // cout<<ftd(s1, s2, s1.size(), s2.size());

    // bottom-up
    dp.resize(5005, vec(5005, 0));
    
    // base case
    dp[0][0] = 0;
    for(int i = 1 ; i <= s1.size() ; i++){
        dp[i][0] = i;
    }
    for(int i = 1 ; i <= s2.size() ; i++){
        dp[0][i] = i;
    }

    // tabulation
    for(int i = 1 ; i <= s1.size() ; i++){
        for(int j = 1 ; j <= s2.size() ; j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = 1 + min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]);
            }
        }
    }
    cout<<dp[s1.size()][s2.size()];
    return 0;
}