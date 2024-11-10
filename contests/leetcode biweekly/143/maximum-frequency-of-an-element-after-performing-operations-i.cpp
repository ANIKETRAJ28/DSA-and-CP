#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int operations) {
        int n = nums.size();
        unordered_map<int, int> freq, range;
        int minRange = 1e9, maxRange = -1e9;
        for(int i = 0 ; i < n ; i++) {
            freq[nums[i]]++;
            int leftRange = nums[i] - k;
            int rightRange = nums[i] + k;
            range[leftRange]++;
            range[rightRange+1]--;
            minRange = min(minRange, leftRange);
            maxRange = max(maxRange, rightRange);
        }
        int ans = 1;
        for(int i = minRange ; i <= maxRange ; i++) {
            range[i] += range[i-1];
            int currEleFreq = freq[i];
            int maxOperations = range[i] - currEleFreq;
            maxOperations = min(maxOperations, operations);
            ans = max(ans, maxOperations+currEleFreq);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}