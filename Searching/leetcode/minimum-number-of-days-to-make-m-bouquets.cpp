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
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        int lo = INT_MAX, hi = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            lo = min(lo, arr[i]);
            hi = max(hi, arr[i]);
        }
        int ans = -1;
        while(lo <= hi){
            int cnt = 0, f_cnt = 0;
            int mid = lo + (hi - lo)/2;
            for(int i = 0 ; i < n ; i++){
                if(arr[i] <= mid) cnt++;
                else{
                    f_cnt += cnt/k;
                    cnt = 0;
                }
            }
            f_cnt += cnt/k;
            if(f_cnt < m) lo = mid+1;
            else{
                ans = mid;
                hi = mid-1;
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}