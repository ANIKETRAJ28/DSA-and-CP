//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
  int solve(string s, int k)
  {
    // code here
    int n = s.size();
    int maxi = INT_MAX;
    int mini = INT_MIN;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '0')
        continue;
      int c_maxi = min(n - 1, i + k);
      int c_mini = max(0, i - k);
      if (c_mini <= maxi)
      {
        if (mini == INT_MIN && maxi == INT_MAX)
        {
          mini = c_mini;
          maxi = c_maxi;
        }
        else
        {
          maxi = c_maxi;
        }
      }
      else
      {
        ans += (maxi - mini + 1);
        maxi = c_maxi;
        mini = c_mini;
      }
    }
    if (maxi != INT_MIN)
      ans += (maxi - mini + 1);
    return ans;
  }
};

//{ Driver Code Starts.

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    string s;
    cin >> s;
    int K;
    cin >> K;
    Solution obj;
    cout << obj.solve(s, K) << "\n";

    cout << "~" << "\n";
  }
}
// } Driver Code Ends