#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    int dp[50005][2];
    int profit(vector<int> &prices, int i, bool flag, int fees) {
        if(i == prices.size()) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        int ans = INT_MIN;
        ans = profit(prices, i+1, flag, fees);
        // buy
        if(flag) {
            ans = max(ans, profit(prices, i+1, !flag, fees)-prices[i]);
        } else {
            ans = max(ans, profit(prices, i+1, !flag, fees)+prices[i]-fees);
        }
        return dp[i][flag] = ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return profit(prices, 0, true, fee);
    }
};

int main() {
    
    return 0;
}