#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://youtu.be/vGI75BQhDVI?si=XTo6JUi88NgK3A2S
// https://leetcode.com/problems/maximum-strength-of-k-disjoint-subarrays/

/**
 * Constraints:
 * 1 <= n <= 104
 * -109 <= nums[i] <= 109
 * 1 <= k <= n
 * 1 <= n * k <= 106
 * k is odd.
*/

/**
 * TC = O(n*k)
 * SC = O(n*k)
*/

class Solution {
public:
    #define ll long long
    vector<vector<vector<ll>>> dp;
    ll ftd(vector<int>& nums, int i, ll k, bool start_new) {
        // base case
        if(k == 0) return 0;
        if(i >= nums.size()) return -1e18;
        if(dp[i][k][start_new] != -1) return dp[i][k][start_new];

        ll not_take = -1e18;
        ll take = -1e18;

        // not take
        if(start_new) {
            not_take = ftd(nums, i+1, k, true);
        }

        // take
        if(k%2) {
            // take and create new subarray
            take = ftd(nums, i+1, k-1, true) + nums[i]*k;
            // take and continue with same subarray
            take = max(take, ftd(nums, i+1, k, false) + nums[i]*k);
        } else {
            // take and create new subarray
            take = ftd(nums, i+1, k-1, true) - nums[i]*k;
            // take and continue with same subarray
            take = max(take, ftd(nums, i+1, k, false) - nums[i]*k);
        }
        return dp[i][k][start_new] = max(take, not_take);
    }
    long long maximumStrength(vector<int>& nums, int k) {
        dp.resize(nums.size()+1, vector<vector<ll>> (k+1, vector<ll> (3, -1)));
        return ftd(nums, 0, k, true);
    }
};

int main() {
    
    return 0;
}