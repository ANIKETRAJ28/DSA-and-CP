#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        int mini = INT_MAX;
        while(lo <= hi) {
            int mid = lo + (hi - lo) /2;
            mini = min(mini, nums[mid]);
            if(nums[hi] < nums[mid]) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return mini;
    }
};

int main() {
    
    return 0;
}