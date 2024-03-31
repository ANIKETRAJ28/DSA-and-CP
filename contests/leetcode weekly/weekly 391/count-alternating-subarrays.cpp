#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-alternating-subarrays/description/

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        long long ans = 0;
        int i = 0, j = 1;
        while(j < n) {
            while(j < n && nums[j] != nums[j-1]) {
                j++;
            }
            while(i < j) {
                ans += j-i;
                i++;
            }
            j++;
        }
        if(i < n) ans += j-i;
        return ans;
    }
};

int main() {
    
    return 0;
}