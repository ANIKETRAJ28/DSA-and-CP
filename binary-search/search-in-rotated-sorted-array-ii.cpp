#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
/**
 * imp eg:
 * [1,0,1,1,1]  0
 * [5,1,3]  3
 * [4,5,6,7,0,1,2]  0
 * [1,0,1,1,1]  0
 */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        while(lo <= hi) {
            int mid = lo + (hi-lo) /2;
            if (nums[mid] == target)
                return true;
			// with duplicates we can have this contdition, just update left & right
            if((nums[lo] == nums[mid]) && (nums[hi] == nums[mid])) {
                lo++;
                hi--;
            }
			// first half
            else if(nums[lo] <= nums[mid]) { // first half is in order
				// target is in first  half as it is sorted so, if first element is smaller or equal to target and middle is greater than it hi = mid-1 
                if((nums[lo] <= target) && (nums[mid] > target)) hi = mid - 1;
                else lo = mid + 1;
            }
			// second half
            else { // second half is order
                // same goes with second half just mid will be lo and hi will be mid
                if((nums[mid] < target) && (nums[hi]>= target)) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    
    return 0;
}