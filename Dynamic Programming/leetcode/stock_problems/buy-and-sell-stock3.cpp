#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

class Solution {
public:
    int dp[100005][3][2];
    int ftd(vector<int>& prices, int i, int k, bool flag) {
        // base case
        if(i >= prices.size() or k <= 0) return 0;
        if(dp[i][k][flag] != -1) return dp[i][k][flag];
        // skip
        int res = INT_MIN;
        res = max(res, ftd(prices, i+1, k, flag));
        // buy stocks
        if(flag) {
            res = max(res, ftd(prices, i+1, k, false) - prices[i]);
        }
        // sell stock
        else {
            res = max(res, ftd(prices, i+1, k-1, true) + prices[i]);
        }
        return dp[i][k][flag] = res;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return ftd(prices, 0, 2, true);
    }
};

int main() {
    
    return 0;
}