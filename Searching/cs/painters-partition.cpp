#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557?leftPanelTabValue=SUBMISSION

int findLargestMinDistance(vector<int> &nums, int k)
{
    //    Write your code here.
    int n = nums.size();
    int lo = 0, hi = 0;
    for(int i = 0 ; i < n ; i++){
        lo = max(lo, nums[i]);
        hi += nums[i];
    }
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        int cnt = 0, ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans += nums[i];
            if(ans > mid){
                cnt++;
                ans = nums[i];
            }
        }
        if(cnt >= k){
            lo = mid+1;
        }
        else hi = mid-1;
    }
    return lo;
}

int main(){
    
    return 0;
}