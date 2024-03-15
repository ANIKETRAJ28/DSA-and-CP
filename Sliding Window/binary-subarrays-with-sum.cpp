#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/binary-subarrays-with-sum/description/

class Solution {
public:
    int atmost(vector<int> &nums, int goal) {
        int n = nums.size();
        int res = 0;
        int sum = 0;
        int i = 0, j = 0;
        while(i < n) {
            sum += nums[i];
            while(sum > goal and j <= i) {
                sum -= nums[j];
                j++;
            }
            res += i-j+1;
            i++;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal-1);
    }
};

int main() {
    
    return 0;
}