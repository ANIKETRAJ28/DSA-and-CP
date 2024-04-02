#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0, j = 0;
        int maxi = INT_MIN, mini = INT_MAX;
        multiset<int, greater<int>> mst;
        int ans = 0;
        while(j < n) {
            mst.insert(nums[j]);
            int diff = (*mst.begin() - *mst.rbegin());
            while(i <= j and diff > limit) {
                ans = max(ans, j-i);
                mst.erase(mst.find(nums[i]));
                diff = (*mst.begin() - *mst.rbegin());
                i++;
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