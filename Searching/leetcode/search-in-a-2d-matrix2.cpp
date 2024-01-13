#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        // O(nlogm)
        for(int row = 0 ; row < n ; row++){
            int lo = 0, hi = m-1;
            while(lo <= hi){
                int col = lo + (hi - lo)/2;
                if(matrix[row][col] == target) return true;
                else if(matrix[row][col] < target) lo = col+1;
                else hi = col-1;
            }
        }
        return false;
        // O(m+n)
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = m-1;
        while(row < n and col >= 0){
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) row++;
            else col--;
        }
        return false;
    }
};

int main(){
    
    return 0;
}