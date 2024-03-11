#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-center-of-star-graph/description/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> first = edges[0];
        vector<int> second = edges[1];
        if(edges[0][0] == edges[1][0]) return edges[0][0];
        else if(edges[0][0] == edges[1][1]) return edges[0][0];
        return edges[0][1];
    }
};

int main() {
    
    return 0;
}