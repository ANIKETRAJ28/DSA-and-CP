#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)n < (long long)m*k) return -1;
        int ans = -1;
        int lo = INT_MAX, hi = INT_MIN;
        for(int i = 0 ; i < n ; i++) {
            lo = min(lo, bloomDay[i]);
            hi = max(hi, bloomDay[i]);
        }
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int b_cnt = 0, f_cnt = 0;
            for(int i = 0 ; i < n ; i++) {
                if(bloomDay[i] <= mid) f_cnt++;
                else {
                    // for making sure for at every non blooming point we can store bouquet
                    // 1 bouquet contains k adjacent flowers
                    // then set cnt = 0
                    b_cnt += (f_cnt/k);
                    f_cnt = 0; 
                }
            }
            b_cnt += (f_cnt/k);
            if(b_cnt >= m) {
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