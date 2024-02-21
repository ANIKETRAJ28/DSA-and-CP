#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/shortest-uncommon-subsequence5746/1

// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> dp;
    long long int ftd(string &s1, string &s2, int i, int j) {
        // base case
        if(i >= s1.size()) return 1e9;
        if(j == s2.size()) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        long long int ans = INT_MAX;
        int k = j;
        for(k ; k < s2.size() ; k++) {
            if(s1[i] == s2[k]) break;
        }
        if(k == s2.size()) return 1;
        return dp[i][j] = min(ftd(s1, s2, i+1, j), 1 + ftd(s1, s2, i+1, k+1));
    }
    int shortestUnSub(string S, string T) {
        // code here
        dp.resize(505, vector<int>(505, -1));
        long long int ans = ftd(S, T, 0, 0);
        if(ans >= 1e9) return -1;
        return (int)ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}