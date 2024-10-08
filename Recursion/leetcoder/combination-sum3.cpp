#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/combination-sum-iii/submissions/

class Solution {
public:
    void combinations(vector<vector<int>> &result, vector<int> &ans, int i, int k, int sum) {
        if(sum == 0 || i > 9) {
            if(sum == 0 && ans.size() == k) result.push_back(ans);
            return;
        }
        if(ans.size() < k && i <= sum) {
            ans.push_back(i);
            combinations(result, ans, i+1, k, sum-i);
            ans.pop_back();
        }
        combinations(result, ans, i+1, k, sum);
    } 
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> ans;
        combinations(result, ans, 1, k, n);
        return result;
    }
};

class Solution {
public:
vector<vector<int>> ans;
    void f(int k, vector<int> sum, int i, int t) {
        if(t == 0 and k == 0) {
            ans.push_back(sum);
            return;
        }
        if(t < 0 or k < 0) {
            return;
        }

        for(int j = i ; j < 10 ; j++) {
            sum.push_back(j);
            f(k-1, sum, j+1, t-j);
            sum.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> sum;
        f(k, sum, 1, n);
        return ans;
    }
};

int main(){
    
    return 0;
}