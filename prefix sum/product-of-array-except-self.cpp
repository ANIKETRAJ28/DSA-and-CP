#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/product-of-array-except-self/

// O(n) sapce
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        // prefix array
        int p = nums[0];
        pre[0] = 1;
        for(int i = 1 ; i < n ; i++)
        {
            pre[i] = p;
            p *= nums[i];
        }
        // suffix array
        // suffix array * prefix array
        p = nums[n-1];
        for(int i = n-2 ; i >= 0 ; i--)
        {
            pre[i] *= p;
            p *= nums[i];
        }
        return pre;
    }
};

// O(1) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, zero = 0;
        bool flag = true;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == 0) {
                zero++;
            }
            else prod *= nums[i];
        }
        if(zero > 1) {
            for(int i = 0 ; i < n ; i++) {
                nums[i] = 0;
            }
            return nums;
        }
        if(zero != 0) {
            for(int i = 0 ; i < n ; i++) {
                if(nums[i] == 0) {
                    nums[i] = prod;
                }
                else nums[i] = 0;
            }
        }
        else {
            for(int i = 0 ; i < n ; i++) {
                nums[i] = prod / nums[i];
            }
        }
        return nums;
    }
};

int main() {
    
    return 0;
}