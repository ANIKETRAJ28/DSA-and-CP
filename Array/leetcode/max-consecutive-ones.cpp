#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, maxCnt = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == 0) {
                maxCnt = max(cnt, maxCnt);
                cnt = 0;
            } else cnt++;
        }
        return max(maxCnt, cnt);
    }
};

int main() {
    
    return 0;
}