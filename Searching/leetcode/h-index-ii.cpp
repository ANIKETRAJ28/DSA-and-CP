#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/h-index-ii/description/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int lo = 0, hi = n-1;
        int ans = 0;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(citations[mid] >= n-mid) {
                ans = n-mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int lo = 0, hi = citations[n-1];
        int ans = 0;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            bool flag = true;
            int strt = 0, end = n-1;
            for(int i = 0 ; i < n ; i++) {
                if(citations[i] >= mid) {
                    if(n-i >= mid) flag = false;
                    break;
                }
            }
            if(!flag) {
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}