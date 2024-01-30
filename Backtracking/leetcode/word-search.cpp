#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/word-search/description/

class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    int n = 0, m = 0, l = 0;

    bool check(vector<vector<char>>& board, string &word, int i, int j, int k) {
        return j >= 0 and k >= 0 and j < n and k < m and board[j][k] == word[i];
    }

    bool f(vector<vector<char>>& board, string &word, int i, int j, int k) {
        // base case
        if(i == l-1) return true;

        char c = board[j][k];
        board[j][k] = '*';
        for(int d = 0 ; d < 4 ; d++) {
            if(check(board, word, i+1, j+dx[d], k+dy[d]))
            if(f(board, word, i+1, j+dx[d], k+dy[d])) return true;
        }
        board[j][k] = c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        l = word.size();
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(board[i][j] == word[0]) {
                    if(f(board, word, 0, i, j)) return true;
                }
            }
        }
        return false;
    }
};

int main(){
    
    return 0;
}