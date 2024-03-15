#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:
    int atmost(vector<int> &nums, int goal) {
            int n = nums.size();
            int res = 0;
            int sum = 0;
            int i = 0, j = 0;
            while(i < n) {
                if(nums[i]%2 == 1) sum++;
                while(sum > goal and j <= i) {
                    if(nums[j]%2 == 1) sum--;
                    j++;
                }
                res += i-j+1;
                i++;
            }
            return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};

int main() {
    
    return 0;
}