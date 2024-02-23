#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/triangle/submissions/

class Solution {
public:
    vector<vector<int>> dp;
    int ftd(vector<vector<int>>& triangle, int i, int j) {
        // base case
        if(i == triangle.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = triangle[i][j] + min(ftd(triangle, i+1, j), ftd(triangle, i+1, j+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // dp.resize(201, vector<int> (201, -1));
        // return ftd(triangle, 0, 0);
        dp.resize(201, vector<int> (201, 0));
        int n = triangle.size();
        for(int i = n-1 ; i >= 0 ; i--) {
            for(int j = n-1 ; j >= 0 ; j--) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
            n--;
        }
        return dp[0][0];
    }
};

int main() {
    
    return 0;
}