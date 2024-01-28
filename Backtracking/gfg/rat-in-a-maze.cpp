//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    bool trace(vector<vector<int>> &m, int i, int j) {
        int n = m.size();
        if(i < 0 or i >= n or j < 0 or j >= n or m[i][j] == 0) return false;
        return true;
    }
    void path(vector<vector<int>> &m, string str, int i, int j) {
        int n = m.size();
        if(i == n-1 and j == n-1) {
            ans.push_back(str);
            return;
        }
        m[i][j] = 0;
        // upper side
        if(trace(m, i-1, j)) {
            path(m, str+'U', i-1, j);
        }
        // bottom side
        if(trace(m, i+1, j)) {
            path(m, str+'D', i+1, j);
        }
        // right side
        if(trace(m, i, j+1)) {
            path(m, str+'R', i, j+1);
        }
        // left side
        if(trace(m, i, j-1)) {
            path(m, str+'L', i, j-1);
        }
        m[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[n-1][n-1] == 0 or m[0][0] == 0) return {"-1"};
        path(m, "", 0, 0);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends