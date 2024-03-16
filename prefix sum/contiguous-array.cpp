#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/contiguous-array/description

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> helper;
        int n = nums.size();
        vector<int> sum(n, 0);
        int count = 0;
        int ans = 0;
        helper.insert({0, -1});
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == 1) count++;
            else count--;
            if(helper.find(count) != helper.end()) {
                int idx = helper[count];
                ans = max(ans, i - idx);
            } else {
                helper.insert({count, i});
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}