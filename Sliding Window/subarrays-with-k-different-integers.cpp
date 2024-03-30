#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/subarrays-with-k-different-integers/description

class Solution {
public:
    int minSumSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int i = 0, j = 0;
        int cnt = 0;
        while(j < n) {
            mp[nums[j]]++;
            while(mp.size() > k) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            cnt += j-i+1;
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return minSumSubarray(nums, k) - minSumSubarray(nums, k-1);
    }
};

int main() {
    
    return 0;
}