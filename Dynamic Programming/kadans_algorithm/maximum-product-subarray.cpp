#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = 1;
        int n = nums.size();
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++) {
            prod *= nums[i];
            ans = max(ans, prod);
            if(prod == 0) {
                prod = 1;
            }
        }
        prod = 1;
        for(int i = n-1 ; i >= 0 ; i--) {
            prod *= nums[i];
            ans = max(ans, prod);
            if(prod == 0) {
                prod = 1;
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}