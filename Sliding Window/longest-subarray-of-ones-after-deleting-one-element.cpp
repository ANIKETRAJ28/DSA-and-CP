#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = 0;
        bool flag = true;
        int i = 0, j = 0;
        int n = nums.size();
        while(j < n) {
            if(nums[j] == 1) j++;
            else if(nums[j] == 0) {
                if(flag) {
                    flag = false;
                    j++;
                }
                else {
                    len = max(len, j-i-1);
                    while(nums[i] != 0) i++;
                    i++;
                    flag = true;
                }
            }
        }
        return (j-i-1 > len) ? j-i-1 : len;
    }
};

int main() {
    
    return 0;
}