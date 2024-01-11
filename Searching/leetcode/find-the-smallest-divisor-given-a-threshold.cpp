#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int lo = 1, hi = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            hi = max(hi, nums[i]);
        }
        int ans = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int cnt = 0;
            for(int i = 0 ; i < n ; i++){
                cnt += nums[i]/mid;
                if(nums[i]%mid != 0) cnt++;
            }
            if(cnt <= threshold){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}