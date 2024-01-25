#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/subsets/description/

class Solution {
public:
    vector<vector<int>> ans;
    void subset(int i, vector<int> &nums, vector<int> v) {
        int n = nums.size();
        if(i == n) {
            ans.push_back(v);
            return;
        }
        subset(i+1, nums, v);
        v.push_back(nums[i]);
        subset(i+1, nums, v);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        subset(0, nums, v);
        return ans;
    }
};

int main(){
    
    return 0;
}