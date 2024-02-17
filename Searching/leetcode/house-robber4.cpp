#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/house-robber-iv/description/

class Solution {
public:
    bool check(vector<int>& nums, int k, int mid) {
        int n = nums.size();
        int i = 0;
        while(i < n) {
            if(nums[i] <= mid) {
                i+=2;
                k--;
            }
            else i++;
            if(k == 0) return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int hi = -1, lo = 1;
        for(int i = 0 ; i < n ; i++) {
            hi = max(hi, nums[i]);
        }
        int ans = -1;
        while(lo < hi) {
            int mid = (lo + hi)/2;
            if(check(nums, k, mid)) {
                hi = mid;
            }
            else lo = mid+1;
        }
        return hi;
    }
};

int main() {
    
    return 0;
}