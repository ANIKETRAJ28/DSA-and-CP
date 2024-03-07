#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:
    int subarrays(vector<int>& nums, int k) {
        int cnt = 0, ans = 0, i = 0, j = 0;
        int n = nums.size();
        while(j < n) {
            if(nums[j]%2) cnt++;
            while(cnt > k) {
                if(nums[i]%2) cnt--;
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subarrays(nums, k) - subarrays(nums, k-1);
    }
};

int main() {
    
    return 0;
}