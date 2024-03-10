#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/h-index/description/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
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

int main() {
    
    return 0;
}