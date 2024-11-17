#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/zero-array-transformation-i/

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> freq(n, 0);
        for(int i = 0 ; i < m ; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            freq[l]--;
            if(r < n-1) freq[r+1]++;
        }
        for(int i = 1 ; i < n ; i++) {
            freq[i] += freq[i-1];
        }
        for(int i = 0 ; i < n ; i++) {
            nums[i] += freq[i];
            if(nums[i] > 0) return false;
        }
        return true;
    }
};

int main() {
    
    return 0;
}