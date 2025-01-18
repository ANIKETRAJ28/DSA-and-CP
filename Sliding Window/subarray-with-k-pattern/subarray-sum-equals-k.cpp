#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    #define ll long long int
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp.insert({0,1});
        int ans = 0;
        int count = 0;
        for(int i = 0 ; i < n ; i++) {
            ans += nums[i];
            if(mp.find(ans-k) != mp.end()) count += mp[ans-k];
            mp[ans]++;
        }
        return count;
    }
};

int main() {
    
    return 0;
}