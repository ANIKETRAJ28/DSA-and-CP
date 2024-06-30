#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int lo = 0, hi = n-1;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(mid == 0) lo = mid+1;
            else if(mid == n-1) hi = mid-1;
            else if(arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid]) return mid;
            else if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1]) lo = mid+1;
            else hi = mid-1;
        }
        return -1;
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int lo = 1, hi = n-2;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(arr[mid] < arr[mid+1] and arr[mid] < arr[mid-1]) return mid-1;
            if(arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]) return mid;
            // strict increasing
            if(arr[mid] < arr[mid+1] and arr[mid] > arr[mid-1]) lo = mid+1;
            else hi = mid-1;
        }
        return -1;
    }
};

int main() {
    
    return 0;
}