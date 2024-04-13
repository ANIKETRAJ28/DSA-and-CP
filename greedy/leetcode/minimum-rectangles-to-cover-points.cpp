#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-rectangles-to-cover-points/description/

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int n = points.size();
        if(n == 1) return 1;
        sort(points.begin(), points.end());
        int ans = 0;
        int len = points[0][0];
        int i = 1;
        while(i < n) {
            if(points[i][0] - len <= w) i++;
            else {
                ans++;
                len = points[i][0];
            }
        }
        return ans+1;
    }
};

int main() {
    
    return 0;
}