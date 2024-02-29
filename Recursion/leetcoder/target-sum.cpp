#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/target-sum/description/

class Solution {
public:
vector<vector<int>> dp;
    int ftd(vector<int>& nums, int t, int i, int trgt) {
        if(i == nums.size() and t == trgt) return 1;
        if(i >= nums.size()) return 0;
        return ftd(nums, t+nums[i], i+1, trgt) + ftd(nums, t-nums[i], i+1, trgt);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return ftd(nums, 0, 0, target);
    }
};

int main() {
    
    return 0;
}