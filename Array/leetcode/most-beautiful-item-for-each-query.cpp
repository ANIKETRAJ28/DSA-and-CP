#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/most-beautiful-item-for-each-query/description/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        sort(items.begin(), items.end());
        int currMax = -1e9;
        for(int i = 1 ; i < n ; i++) {
            items[i][1] = max(items[i][1], items[i-1][1]);
        }
        int m = queries.size();
        vector<vector<int>> queryList(m, vector<int> (2));
        for(int i = 0 ; i < m ; i++) {
            queryList[i][0] = queries[i];
            queryList[i][1] = i;
        }
        sort(queryList.begin(), queryList.end());
        vector<int> ans(m, 0);
        for(int i = 0 ; i < m ; i++) {
            int maxVal = -1e9;
            int lo = 0, hi = n-1;
            while(lo <= hi) {
                int mid = lo + (hi - lo)/2;
                if(items[mid][0] > queryList[i][0]) hi = mid-1;
                else {
                    if(items[mid][1] >= maxVal) {
                        maxVal = items[mid][1];
                    }
                    lo = mid+1;
                }
            }
            ans[queryList[i][1]] = maxVal == -1e9 ? 0 : maxVal;
        }
        return ans;

    }
};

int main() {
    
    return 0;
}