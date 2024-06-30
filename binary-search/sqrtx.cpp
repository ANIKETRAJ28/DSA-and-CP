#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x) {
        int lo = 1, hi = x;
        int res = 0;
        while(lo <= hi) {
            long long int mid = lo + (hi - lo)/2;
            if(mid*mid > (long long int)(x)) hi = mid-1;
            else {
                res = mid;
                lo = mid+1;
            }
        }
        return res;
    }
};

int main() {
    
    return 0;
}