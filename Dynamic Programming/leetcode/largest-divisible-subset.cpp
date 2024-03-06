#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/largest-divisible-subset/description/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(1005, 1);
        sort(nums.begin(), nums.end());
        for(int i = n-2 ; i >= 0 ; i--) {
            int maxi = 0;
            for(int j = i+1 ; j < n ; j++) {
                if(nums[j] % nums[i] == 0) {
                    maxi = max(maxi, dp[j]);
                }
            }
            dp[i] += maxi;
        }
        int maxi = 1;
        for(int i = 0 ; i < n ; i++) {
            maxi = max(maxi, dp[i]);
        }
        int val = -1;
        vector<int> ans;
        for(int i = 0 ; i < n ; i++) {
            if(maxi == dp[i] and (val == -1 or !(nums[i]%val))) {
                ans.push_back(nums[i]);
                maxi--;
                val = nums[i];
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}