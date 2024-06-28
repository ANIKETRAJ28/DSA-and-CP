#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, k = n-1;
        while(j <= k) {
            if(nums[j] == 0) {
                swap(nums[i], nums[j]);
                i++; j++;
            } else if(nums[j] == 2) {
                swap(nums[j], nums[k]);
                k--;
            } else {
                j++;
            }
        }
    }
};

int main() {
    
    return 0;
}