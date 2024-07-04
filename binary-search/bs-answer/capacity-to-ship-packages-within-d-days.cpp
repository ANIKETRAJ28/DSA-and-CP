#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = INT_MIN, hi = 0;
        int n = weights.size();
        for(int i = 0 ; i < n ; i++) {
            lo = max(lo, weights[i]);
            hi += weights[i];
        }
        int ans = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            int d = 1;
            for(int i = 0 ; i < n ; i++) {
                if(d > days) break;
                cnt += weights[i];
                if(cnt > mid) {
                    d++;
                    cnt = weights[i];
                }
            }
            if(d <= days) {
                ans = mid;
                hi = mid-1;
            } else lo = mid+1;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}