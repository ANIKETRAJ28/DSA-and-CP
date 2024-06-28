#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        while(j < n) {
            if(nums[j] == nums[i]) j++;
            else {
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        int cnt = 1;
        while(j < n) {
            if(nums[j] == nums[i]) j++;
            else {
                nums[++i] = nums[j];
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    
    return 0;
}