#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/contest/biweekly-contest-126/problems/mark-elements-on-array-by-performing-queries/

class Solution {
public:
#define pp pair<long long, long long>
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        long long sum = 0;
        vector<long long> ans(m);
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        
        for(int i = 0 ; i < n ; i++) {
            pq.push({nums[i], i});
            sum += nums[i];
        }

        for(int j = 0 ; j < m ; j++) {
            vector<int> query = queries[j];
            int idx = query[0];
            int cnt = query[1];
            sum -= nums[idx];
            nums[idx] = 0;
            while(not pq.empty() and cnt > 0) {
                auto ele = pq.top();
                pq.pop();
                int eleIdx = ele.second;
                if(nums[eleIdx]) {
                    sum -= ele.first;
                    nums[eleIdx] = 0;
                    cnt--;
                }
            }
            ans[j] = sum;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}