#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int n = nums.size();
        while(j < n) {
            mp[nums[j]]++;
            int cnt = mp[nums[j]];
            if(cnt > k) {
                ans = max(ans, j-i);
                while(cnt > k) {
                    if(nums[i] == nums[j]) cnt--;
                    mp[nums[i]]--;
                    i++;
                }
            }
            j++;
        }
        ans = max(ans, j-i);
        return ans;
    }
};

int main() {
    
    return 0;
}