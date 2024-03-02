#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, mxSum = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            if(mxSum < sum) mxSum = sum;
            if(sum < 0) sum = 0;
        }
        return mxSum;
    }
};

int main() {
    
    return 0;
}