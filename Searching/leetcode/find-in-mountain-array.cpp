#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-in-mountain-array/description/

/**
 * ! This is the MountainArray's API interface.
 * ! You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class MountainArray {
  public:
    int get(int index);
    int length();
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int lo = 0, hi = n-1;
        while(lo != hi) {
            int mid = lo + (hi - lo)/2;
            if(arr.get(mid) < arr.get(mid+1)) lo = mid+1;
            else hi = mid;
        }
        int peak = lo;
        
        lo = 0, hi = peak;
        while(lo != hi) {
            int mid = lo + (hi - lo)/2;
            if(arr.get(mid) < target) lo = mid+1;
            else hi = mid;
        }
        if(arr.get(lo) == target) return lo;
        
        lo = peak+1, hi = n-1;
        while(lo != hi) {
            int mid = lo + (hi - lo)/2;
            if(arr.get(mid) > target) lo = mid+1;
            else hi = mid;
        }
        if(arr.get(lo) == target) return lo;
        return -1;
    }
};

int main() {
    
    return 0;
}