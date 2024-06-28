#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/rearrange-array-elements-by-sign/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int j = 0;
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] < 0) continue;
            ans[j] = nums[i];
            j+=2;
        }
        j = 1;
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] >= 0) continue;
            ans[j] = nums[i];
            j+=2;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}