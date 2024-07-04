#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long int lo = 1, hi = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            hi += nums[i];
        }
        int ans = -1;
        while(lo <= hi) {
            long long int mid = lo + (hi - lo) / 2;
            long long int cnt = 0;
            for(int i = 0 ; i < n ; i++) {
                if(cnt > (long long int)threshold) break;
                cnt += nums[i]/mid;
                cnt += (nums[i]%mid != 0);
            }
            if(cnt <= (long long int)threshold) {
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