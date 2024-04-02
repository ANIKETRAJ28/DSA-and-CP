#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-the-number-of-good-subarrays/description/

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long ans = 0, pair = 0;
        unordered_map<int, int> mp;
        while(j < n) {
            mp[nums[j]]++;
            pair += (mp[nums[j]]-1);
            while(i < j and pair >= k) {
                ans += n-j;
                mp[nums[i]]--;
                pair -= mp[nums[i]];
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
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