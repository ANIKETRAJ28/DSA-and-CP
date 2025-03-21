//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  int minOperations(vector<int> a, int n)
  {
    // Code here
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
      mp[a[i]]++;
    }
    int maxEle = -1;
    int maxFreq = -1;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
      if (it->first > maxEle)
      {
        maxEle = it->first;
        maxFreq = it->second;
      }
    }
    int idx = -1;
    int maxSubarray = -1;
    for (int i = 0; i < n; i++)
    {
      if (a[i] == maxEle && idx == -1)
      {
        idx = i;
      }
      else if (a[i] != maxEle && idx != -1)
      {
        maxSubarray = max(maxSubarray, i - idx);
        idx = -1;
      }
    }
    if (idx != -1)
    {
      maxSubarray = max(maxSubarray, n - idx);
    }
    return maxFreq - maxSubarray;
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    Solution ob;
    cout << ob.minOperations(a, n) << "\n";

    cout << "~" << "\n";
  }
}

// } Driver Code Ends