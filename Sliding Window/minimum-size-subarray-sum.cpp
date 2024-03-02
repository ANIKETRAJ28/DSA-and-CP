#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int len = INT_MAX;
        int i = 0, j = 0;
        while(j < n) {
            if(sum < target) {
                sum += nums[j];
            }
            while(sum >= target) {
                len = min(len, j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return (len == INT_MAX) ? 0 : len;
    }
};

int main() {
    
    return 0;
}