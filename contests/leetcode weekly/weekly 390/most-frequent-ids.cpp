#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/most-frequent-ids/description/

class Solution {
public:
    #define ll long long
    #define pp pair<ll, ll>
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        set<pp, greater<pp>> st;
        unordered_map<ll, ll> mp;
        vector<ll> ans(n);
        for(int i = 0 ; i < n ; i++) {
            pp curr = {mp[nums[i]], nums[i]};
            if(st.find(curr) != st.end()) st.erase(curr);
            mp[nums[i]] += freq[i];
            curr = {mp[nums[i]], nums[i]};
            st.insert(curr);
            pp grt = *st.begin();
            ans[i] = grt.first;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}