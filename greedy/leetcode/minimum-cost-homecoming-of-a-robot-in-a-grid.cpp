#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/description/

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCost, vector<int>& colCost) {
        int x1 = min(startPos[0], homePos[0]);
        int y1 = min(startPos[1], homePos[1]);
        int x2 = max(startPos[0], homePos[0]);
        int y2 = max(startPos[1], homePos[1]);
        int ans = 0;
        if(x1 == startPos[0]) {
            for(int i = x1+1 ; i <= x2 ; i++) {
                ans += rowCost[i];
            }
        } else {
            for(int i = x1 ; i < x2 ; i++) {
                ans += rowCost[i];
            }
        }
        if(y1 == startPos[1]) {
            for(int i = y1+1 ; i <= y2 ; i++) {
                ans += colCost[i];
            }
        } else {
            for(int i = y1 ; i < y2 ; i++) {
                ans += colCost[i];
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}