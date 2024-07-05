#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;


// https://www.geeksforgeeks.org/problems/aggressive-cows
class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int lo = 1, hi = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++) hi = max(hi, stalls[i]);
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int cow = k-1;
            int mini = stalls[0];
            for(int i = 1 ; i < n ; i++) {
                if(cow == 0) break;
                if(stalls[i] - mini >= mid) {
                    mini = stalls[i];
                    cow--;
                }
            }
            if(!cow) {
                ans = mid;
                lo = mid+1;
            } else hi = mid-1;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}