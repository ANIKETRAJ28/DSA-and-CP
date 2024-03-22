#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/merge-intervals/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int strt = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> res;
        for(int i = 1 ; i < n ; i++) {
            if(intervals[i][0] <= end) end = max(end, intervals[i][1]);
            else {
                res.push_back({strt, end});
                strt = intervals[i][0];
                end = intervals[i][1];
            }
        }
        res.push_back({strt, end});
        return res;
    }
};

int main() {
    
    return 0;
}