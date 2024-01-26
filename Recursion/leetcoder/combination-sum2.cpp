#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/combination-sum-ii/submissions/

class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int> & c, vector<int> &sum, int i, int t) {
        if(t == 0) {
            ans.push_back(sum);
            return;
        }
        if(t < 0) return;
        int n = c.size();
        for(int j = i ; j < n ; j++) {
            if(j > i and c[j] == c[j-1]) continue;
            sum.push_back(c[j]);
            f(c, sum, j+1, t-c[j]);
            sum.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> sum;
        f(candidates, sum, 0, target);
        return ans;
    }
};

int main(){
    
    return 0;
}