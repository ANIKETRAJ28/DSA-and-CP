#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int minPos = -1, maxPos = -1, pvtPos = -1;
        long long ans = 0;
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] < minK || nums[i] > maxK) pvtPos = i;
            if(nums[i] == minK) minPos = i;
            if(nums[i] == maxK) maxPos = i;
            int temp = min(minPos, maxPos) - pvtPos;
            ans += temp <= 0 ? 0 : temp;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}