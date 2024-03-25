#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-all-duplicates-in-an-array/description

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // O(n) TC and O(n) SC
        // unordered_set<int> st;
        int n = nums.size();
        vector<int> ans;
        // for(int i = 0 ; i < n ; i++) {
        //     if(st.count(nums[i])) ans.push_back(nums[i]);
        //     st.insert(nums[i]);
        // }
        // O(n) TC and O(1) SC
        for(int i = 0 ; i < n ; i++) {
            int idx = abs(nums[i]);
            if(nums[idx-1] < 0) ans.push_back(abs(nums[i]));
            else nums[idx-1] = -nums[idx-1];
        }
        return ans;
    }
};

int main() {
    
    return 0;
}