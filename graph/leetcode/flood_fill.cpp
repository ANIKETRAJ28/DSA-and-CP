#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>> & img, int curr_clr, int clr){
        int n = img.size();
        int m = img[0].size();
        if(sr < 0 || sc < 0 || sr >= n || sc >= m || img[sr][sc] != curr_clr) return;
        
        img[sr][sc] = clr;
        dfs(sr+1, sc, img, curr_clr, clr);
        dfs(sr, sc+1, img, curr_clr, clr);
        dfs(sr-1, sc, img, curr_clr, clr);
        dfs(sr, sc-1, img, curr_clr, clr);
    }

    bool valid(vector<vector<int>> img, int i, int j, int clr){
        int n = img.size();
        int m = img[0].size();
        return (i < n && j < m && i >= 0 && j >= 0 && img[i][j] == clr);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        // dfs(sr, sc, image, image[sr][sc], color);
        queue<pair<int, int>> qu;
        int clr = image[sr][sc];
        qu.push({sr, sc});
        image[sr][sc] = color;
        while(not qu.empty()){
            auto ele = qu.front();
            int i = ele.first;
            int j = ele.second;
            qu.pop();
            image[i][j] = color;
            if(valid(image, i+1, j, clr)) qu.push({i+1, j});
            if(valid(image, i, j+1, clr)) qu.push({i, j+1});
            if(valid(image, i-1, j, clr)) qu.push({i-1, j});
            if(valid(image, i, j-1, clr)) qu.push({i, j-1});
        }
        return image;
    }
};

int main(){
    
    return 0;
}