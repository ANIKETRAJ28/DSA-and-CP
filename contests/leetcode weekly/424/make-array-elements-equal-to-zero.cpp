#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/make-array-elements-equal-to-zero/

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int lSum = 0, rSum = 0;
        for(int i = 0 ; i < n ; i++) {
            rSum += nums[i];
        }
        int cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            lSum += nums[i];
            rSum -= nums[i];
            if(nums[i] == 0) {
                if(abs(lSum - rSum) == 0) cnt+= 2;
                if(abs(lSum - rSum) == 1) cnt++;
            } 
        }
        return cnt;
    }
};

int main() {
    
    return 0;
}