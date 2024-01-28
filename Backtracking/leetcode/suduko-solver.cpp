#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/sudoku-solver/submissions/

class Solution {
public:

    bool check(vector<vector<char>>& board, int r, int c, int num) {
        // col check
        for(int col = 0 ; col < 9 ; col++) {
            if(board[r][col] - '0' == num) return false;
        }
        // row check
        for(int row = 0 ; row < 9 ; row++) {
            if(board[row][c] - '0' == num) return false;
        }
        // small board check
        // finding base row and col
        int row = (r/3)*3, col = (c/3)*3;
        for(int i = row ; i < row+3 ; i++) {
            for(int j = col ; j < col+3 ; j++) {
                if(board[i][j] - '0' == num) return false;
            }
        }
        return true;
    }

    bool suduko(vector<vector<char>>& board, int r, int c) {
        // base case
        if(r == 9) return true;
        if(c == 9) return suduko(board, r+1, 0);
        // if any element is present at the position
        if(board[r][c] != '.') return suduko(board, r, c+1);

        for(int i = 1 ; i <= 9 ; i++) {
            if(check(board, r, c, i)) {
                board[r][c] = '0' + i;
                bool res = suduko(board, r, c+1);
                // check for optimization
                if(res) return true;
                board[r][c] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        suduko(board, 0, 0);
    }
};

int main(){
    
    return 0;
}