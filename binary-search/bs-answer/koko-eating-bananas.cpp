#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 0;
        int n = piles.size();
        for(int i = 0 ; i < n ; i++) hi = max(hi, piles[i]);
        int ans = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int time = 0;
            for(int i = 0 ; i < n ; i++) {
                time += piles[i]/mid;
                if(piles[i]%mid != 0) time++;
                if(time > h) break;
            }
            if(time <= h) {
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