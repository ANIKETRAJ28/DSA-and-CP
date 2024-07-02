#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
/**
 * imp eg:
 * [3,0,1,1,3]
 * [1,2,2,2,0,1,1]
 * [2,0,1,1,1]
 * [1,3,3]
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        int mini = INT_MAX;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            mini = min(mini, nums[mid]);
            if(nums[mid] == nums[lo] && nums[mid] == nums[hi]) {
                lo++; hi--;
            }
            // first half 
            else if(nums[lo] < nums[hi]) { 
                if(nums[mid] <= nums[hi]) { 
                    hi = mid-1;
                } else lo = mid+1;
            }
            // second half 
            else {
                if(nums[mid] <= nums[hi]) {
                    hi = mid-1;
                } else lo = mid+1;
            }
        }
        return mini;
    }
};

int main() {
    
    return 0;
}