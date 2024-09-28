#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int dp[100005][2][2];
    int profit(vector<int> &prices, int i, bool flag, int k) {
        if(i == prices.size() || k == 2) return 0;
        if(dp[i][k][flag] != -1) return dp[i][k][flag];
        // leave
        int ans = profit(prices, i+1, flag, k);
        // buy
        if(flag) {
            ans = max(ans, profit(prices, i+1, !flag, k) - prices[i]);
        } else {
            ans = max(ans, profit(prices, i+1, !flag, k+1) + prices[i]);
        }
        return dp[i][k][flag] = ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return profit(prices, 0, true, 0);
    }
};

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