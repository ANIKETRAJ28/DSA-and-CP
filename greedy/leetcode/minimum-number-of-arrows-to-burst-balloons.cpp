#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int end = points[0][1];
        int cnt = 1;
        for(int i = 1 ; i < n ; i++) {
            if(points[i][0] <= end) {
                end = min(end, points[i][1]);
            } else {
                cnt++;
                end = points[i][1];
            }
        }
        return cnt;
    }
};

int main() {
    
    return 0;
}