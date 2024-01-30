#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/combinations/description/

class Solution {
public:
    vector<vector<int>> ans;
    void combination(int i, int n, int k, vector<int> v) {
        // base case
        if(v.size() == k) {
            ans.push_back(v);
            return;
        }

        for(int j = i ; j <= n ; j++) {
            v.push_back(j);
            combination(j+1, n, k, v);
            v.pop_back();
        }
    } 
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        combination(1, n, k,v);
        return ans;
    }
};

int main(){
    
    return 0;
}