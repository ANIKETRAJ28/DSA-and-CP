#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int operations) {
        int n = nums.size();
        map<int, int> freq, range;
        int minRange = 2e9, maxRange = -2e9;
        for(int i = 0 ; i < n ; i++) {
            freq[nums[i]]++;
            int leftRange = nums[i] - k;
            int rightRange = nums[i] + k;
            range[leftRange]++;
            range[rightRange+1]--;
            range[nums[i]] += 0;
            minRange = min(minRange, leftRange);
            maxRange = max(maxRange, rightRange);
        }
        int ans = 1;
        int prefix = 0;
        for(auto it = range.begin() ; it != range.end() ; it++) {
            it->second += prefix;
            prefix = it->second;
            int currEleFreq = freq[it->first];
            int maxOperations = it->second - currEleFreq;
            maxOperations = min(maxOperations, operations);
            ans = max(ans, maxOperations+currEleFreq);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}