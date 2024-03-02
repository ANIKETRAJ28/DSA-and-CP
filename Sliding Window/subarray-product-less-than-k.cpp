#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/subarray-product-less-than-k/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int cnt = 0;
        int n = nums.size();
        int prod = 1;
        int i = 0, j = 0;
        while(j < n) {
            prod *= nums[j];
            while(prod >= k) {
                cnt += (j-i);
                prod /= nums[i];
                i++;
            }
            j++;
        }
        while(i < n) {
            cnt += (j-i);
            prod /= nums[i];
            i++;
        }
        return cnt;
    }
};
int main() {
    
    return 0;
}