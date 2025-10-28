#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// https://leetcode.com/problems/count-ways-to-choose-coprime-integers-from-rows/description/

class Solution {
public:
  #define ll long long
  // const int mod = 1e9+7;
  // int dp[151];
  int dp[151][151];
  /*MEMOIZATION*/
  int td(vector<vector<int>> &mat, int i, int g) {
    int n = mat.size();
    int m = mat[0].size();
    if(i == n) return g == 1;
    if(dp[i][g] != -1) return dp[i][g];
    ll ans = 0;
    for(int j = 0 ; j < m ; j++) {
        int _g = __gcd(mat[i][j], g);
        ans = (ans + td(mat, i+1, _g))%mod;
    }
    return dp[i][g] = ans;
  }
  /*TABULATION*/
  int bu(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    memset(dp, 0, sizeof dp);
    dp[n][1] = 1;
    for(int i = n-1 ; i >= 0 ; i--) {
      for(int g = 1 ; g <= 150 ; g++) {
        ll ans = 0;
        for(int j = 0 ; j < m ; j++) {
          int _g = __gcd(mat[i][j], g);
          ans = (ans + dp[i+1][_g])%mod;
        }
        dp[i][g] = ans;
      }
    }
    ll ans = 0;
    for(int i = 0 ; i < m ; i++) {
        ans = (ans + dp[1][mat[0][i]])%mod;
    }
    return ans;
  }
  /*SPACE OPTIMIZED*/
  int op(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    int dp[151];
    memset(dp, 0, sizeof dp);
    dp[1] = 1;
    for(int i = n-1 ; i >= 1 ; i--) {
      int temp[151];
      for(int g = 1 ; g <= 150 ; g++) {
        ll ans = 0;
        for(int j = 0 ; j < m ; j++) {
          int _g = __gcd(mat[i][j], g);
          ans = (ans + dp[_g])%mod;
        }
        temp[g] = ans;
      }
      memcpy(dp, temp, sizeof dp);
    }
    ll ans = 0;
    for(int i = 0 ; i < m ; i++) {
        ans = (ans + dp[mat[0][i]])%mod;
    }
    return ans;
  }
  int countCoprime(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    memset(dp, -1, sizeof dp);
    ll ans = 0;
    for(int i = 0 ; i < m ; i++) {
        ans = (ans + td(mat, 1, mat[0][i]))%mod;
    }
    return ans;
    // return bu(mat);
    // return op(mat);
  }
};

int main() {
  fast_io();
  
  return 0;
}