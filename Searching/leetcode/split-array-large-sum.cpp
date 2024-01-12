#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/split-array-largest-sum/description/

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long int lo = 0, hi = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            lo = max(lo, (long long int)nums[i]);
            hi += nums[i];
        }
        long long int ans = 0;
        while(lo <= hi){
            long long int mid = lo + (hi - lo)/2;
            int cnt = 0;
            long long int sum = 0;
            for(int i = 0 ; i < n ; i++){
                if(sum + nums[i] <= mid){
                    sum += nums[i];
                }
                else{
                    cnt++;
                    sum = nums[i];
                }
            }
            if(cnt >= k) lo = mid+1;
            else hi = mid-1;
        }
        return lo;
    }
};

int main(){
    
    return 0;
}