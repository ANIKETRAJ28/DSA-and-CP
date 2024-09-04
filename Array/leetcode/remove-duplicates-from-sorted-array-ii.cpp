#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int cnt = 2, val = nums[0];
        while(i < n && j < n) {
            while(j < n && nums[j] == val) {
                if(cnt > 0) {
                    swap(nums[i], nums[j]);
                    i++;
                    cnt--;
                }
                j++;
            }
            if(j >= n) break;
            cnt = 2;
            val = nums[j];
        }
        return i;
    }
};

int main() {
    
    return 0;
}