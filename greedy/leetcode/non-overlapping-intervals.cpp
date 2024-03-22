#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/non-overlapping-intervals/description/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];
        int cnt = 0;
        for(int i = 1 ;  i < n ; i++) {
            if(intervals[i][0] < end) {
                cnt++;
                end = min(end, intervals[i][1]);
            } else {
                end = max(end, intervals[i][1]);
            }
        }
        return cnt;
    }
};

int main() {
    
    return 0;
}