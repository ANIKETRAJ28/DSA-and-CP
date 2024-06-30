#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) lo = mid+1;
            else hi = mid-1;
        }
        return lo;
    }
};

int main() {
    
    return 0;
}