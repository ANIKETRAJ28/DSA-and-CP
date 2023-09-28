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

    dp.resize(5005, vec(5005, -1));

    cout<<ftd(s1, s2, s1.size(), s2.size());

    return 0;
}