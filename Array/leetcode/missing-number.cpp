#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;
        int sumArr = 0;
        for(int i = 0 ; i < n ; i++)
        sumArr+=nums[i];
        return sum-sumArr;
    }
};

int main() {
    
    return 0;
}