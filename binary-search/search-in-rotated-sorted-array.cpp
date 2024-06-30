#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        eg.
        [4,5,6,7,0,1,2]    3
        [2,3,4,5,1]    5
        [1,2,3,4]   2
        [2,3,4,1]   2
        [2,1]   2
        */
        int n = nums.size();
        int lo = 0, hi = n-1;
        int pivot = INT_MAX;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(nums[mid] <= nums[hi]) {
                if(pivot != INT_MAX && nums[pivot] < nums[mid]) break; // [8,9,2,3,4] for this example
                pivot = mid;
                hi = mid-1;
            } else lo = mid+1;
        }
        lo = 0, hi = pivot;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) {
                lo = mid+1;
            } else hi = mid-1;
        }
        lo = pivot, hi = n-1;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) {
                lo = mid+1;
            } else hi = mid-1;
        }
        return -1;
    }
};

int main() {
    
    return 0;
}