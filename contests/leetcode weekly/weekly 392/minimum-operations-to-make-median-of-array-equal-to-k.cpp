#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k/description/

class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0 ; i <= n/2 ; i++) {
            ans += max(0, nums[i]-k);
        }
        for(int i = n/2 ; i < n ; i++) {
            ans += max(0, k-nums[i]);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}