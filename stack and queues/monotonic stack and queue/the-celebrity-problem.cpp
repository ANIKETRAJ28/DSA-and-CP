//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// https : // www.geeksforgeeks.org/problems/the-celebrity-problem/1

// } Driver Code Ends

class Solution
{
public:
  int celebrity(vector<vector<int>> &mat)
  {
    // code here
    int n = mat.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
      st.push(i);
    }
    while (st.size() > 1)
    {
      int c1 = st.top();
      st.pop();
      int c2 = st.top();
      st.pop();
      if (mat[c1][c2])
      {
        st.push(c2);
      }
      else
      {
        st.push(c1);
      }
    }
    int c1 = st.top();
    st.pop();
    for (int c2 = 0; c2 < n; c2++)
    {
      if (c1 == c2)
        continue;
      if (mat[c1][c2] || !mat[c2][c1])
        return -1;
    }
    return c1;
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> M[i][j];
      }
    }
    Solution ob;
    cout << ob.celebrity(M) << endl;
    cout << "~" << endl;
  }
}

// } Driver Code Ends