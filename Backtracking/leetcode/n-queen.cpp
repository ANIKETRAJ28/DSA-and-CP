#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/n-queens/submissions/

class Solution
{
public:
    vector<vector<char>> grid;
    vector<vector<string>> final_ans;
    bool check(int row, int col, int n)
    {
        // vertical check
        for (int i = row - 1; i >= 0; i--)
        {
            if (grid[i][col] == 'Q')
                return false;
        }
        // left digonal check
        for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--)
        {
            if (grid[i][j] == 'Q')
                return false;
        }
        // right digonal check
        for (int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++)
        {
            if (grid[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void f(int row, int n)
    {
        if (row == n)
        {
            // answer found
            vector<string> result;
            for (int i = 0; i < n; i++)
            {
                string res = "";
                for (int j = 0; j < n; j++)
                {
                    res += grid[i][j];
                }
                result.push_back(res);
            }
            final_ans.push_back(result);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (check(row, col, n))
            {
                grid[row][col] = 'Q';
                f(row + 1, n);
                grid[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        grid.resize(n, vector<char>(n, '.'));
        f(0, n);
        return final_ans;
    }
};

int main()
{

    return 0;
}