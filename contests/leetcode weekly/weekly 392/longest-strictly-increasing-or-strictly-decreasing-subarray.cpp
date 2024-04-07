#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 1) return 1;
        int ans = 0;
        int i = 0, j = 1;
        while(j < n) {
            if(nums[j] <= nums[j-1]) {
                ans = max(ans, j-i);
                i = j;
            }
            j++;
        }
        ans = max(ans, j-i);
        i = 0; j = 1;
        while(j < n) {
            if(nums[j] >= nums[j-1]) {
                ans = max(ans, j-i);
                i = j;
            }
            j++;
        }
        ans = max(ans, j-i);
        return ans;
    }
};

int main() {
    
    return 0;
}