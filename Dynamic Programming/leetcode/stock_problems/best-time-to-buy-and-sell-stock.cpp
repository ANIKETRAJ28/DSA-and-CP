#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> mini(n), maxi(n);
        mini[0] = prices[0];
        maxi[n-1] = prices[n-1];
        for(int i = n-2 ; i >= 0 ; i--) maxi[i] = max(prices[i],maxi[i+1]);
        for(int i = 1 ; i < n ; i++) mini[i] = min(prices[i],mini[i-1]);
        int diff = 0;
        for(int i = 0 ; i < n ; i++) diff = max(diff, maxi[i]-mini[i]);
        return diff;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0, buy = INT_MAX, sell = INT_MIN;
        for(int i = 0 ; i < n ; i++) {
            if(prices[i] < buy) {
                buy = prices[i];
                sell = INT_MIN;
            } else if(prices[i] > sell) {
                sell = prices[i];
                profit = max(profit, sell-buy);
            }
        }
        return profit;
    }
};

int main() {
    
    return 0;
}