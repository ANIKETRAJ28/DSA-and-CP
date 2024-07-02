#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int lo = 0, hi = n-1;
        int ans = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(mid % 2 == 0) {
                if(nums[mid+1] != nums[mid]) {
                    ans = nums[mid];
                    hi = mid-1;
                } else lo = mid+1;
            } else {
                if(nums[mid-1] != nums[mid]) {
                    ans = nums[mid];
                    hi = mid-1;
                } else lo = mid+1;
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}