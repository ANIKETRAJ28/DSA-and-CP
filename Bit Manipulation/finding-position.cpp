//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/finding-position2223/1

// } Driver Code Ends

// User function Template for C++
class Solution
{
public:
  long long int nthPosition(long long int n)
  {
    // code here
    int num = 0;
    while (n)
    {
      num = n;
      n = n & n - 1;
    }
    return num;
  }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long long int n;
    cin >> n;
    Solution ob;
    cout << ob.nthPosition(n) << endl;

    cout << "~" << "\n";
  }
  return 0;
}

// } Driver Code Ends