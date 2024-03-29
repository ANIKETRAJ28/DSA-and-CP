#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        int maxi = -1;
        for(int i = 0 ; i < n ; i++) maxi = max(maxi, nums[i]);
        int cnt = 0;
        int i = 0, j = 0;
        while(j < n) {
            if(nums[j] == maxi) cnt++;
            while(cnt >= k) {
                ans += n-j;
                if(nums[i] == maxi) cnt--;
                i++;
            }
            j++;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}