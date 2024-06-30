#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        int lb = -1, ub = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target) {
                lb = mid;
                hi = mid-1;
            } else if(nums[mid] > target) hi = mid-1;
            else lo = mid+1;
        }
        lo = 0, hi = n-1;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target) {
                ub = mid;
                lo = mid+1;
            } else if(nums[mid] > target) hi = mid-1;
            else lo = mid+1;
        }
        return {lb, ub};
    }
};

int main() {
    
    return 0;
}