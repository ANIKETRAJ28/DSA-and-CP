#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/zero-array-transformation-ii/description/

class Solution {
public:
    bool check(vector<int> nums, vector<vector<int>> &queries, int k) {
        int n = nums.size();
        vector<int> freq(n, 0);
        for(int i = 0 ; i < k ; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            freq[l] -= val;
            if(r < n-1) freq[r+1] += val;
        }
        for(int i = 1 ; i < n ; i++) {
            freq[i] += freq[i-1];
        }
        for(int i = 0 ; i < n ; i++) {
            nums[i] += freq[i];
            if(nums[i] > 0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
       int n = queries.size();
       int lo = 0, hi = n;
       int ans = -1;
       while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
            if(check(nums, queries, mid)) {
                ans = mid;
                hi = mid-1;
            } else lo = mid+1;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}