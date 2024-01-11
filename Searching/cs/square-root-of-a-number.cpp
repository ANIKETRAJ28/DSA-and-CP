#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/square-root-integral_893351?leftPanelTab=0%3Futm_source%3Dstriver

int floorSqrt(int n)
{
    // Write your code here.
    long long int lo = 1, hi = n;
    while(lo <= hi){
        long long int mid = lo + (hi - lo)/2;
        if(mid*mid == (long long int)n) return mid;
        else if(mid*mid > n) hi = mid-1;
        else{
            lo = mid+1;
        }
    }
    return hi;
}


int main(){
    
    return 0;
}