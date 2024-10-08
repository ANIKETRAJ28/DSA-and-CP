#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/description/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < n && nums[i] < 0 && k > 0) {
            nums[i] *= -1;
            k--;
            i++;
        }
        sort(nums.begin(), nums.end());
        int sum = 0;
        i = 0;
        while(i < n) sum += nums[i++];
        if(nums[0] == 0) return sum;
        if(k%2) {
            return sum - 2*nums[0];
        }
        return sum;
    }
};

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
        int n = nums.size();
        while(k--) {
            int ele = minHeap.top();
            minHeap.pop();
            ele *= -1;
            minHeap.push(ele);
        }
        int ans = 0;
        while(not minHeap.empty()) {
            ans += minHeap.top();
            minHeap.pop();
        }
        return ans;
    }
};

int main() {
    
    return 0;
}