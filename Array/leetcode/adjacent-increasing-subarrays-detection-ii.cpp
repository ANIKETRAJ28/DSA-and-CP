#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        int lo = 1, hi = n/2;
        vector<int> strictIncr(n, 1);
        for(int i = n-2 ; i >= 0 ; i--) {
            if(nums[i] < nums[i+1]) strictIncr[i] += strictIncr[i+1];
        }
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            bool flag = true;
            for(int i = 0 ; i < n-mid ; i++) {
                if(strictIncr[i] >= mid && strictIncr[i+mid] >= mid) {
                    flag = false;
                    break;
                }
            }
            if(!flag) {
                lo = mid+1;
                maxLen = mid;
            } else hi = mid-1;
        }
        return maxLen;
    }
};

int main() {
    
    return 0;
}