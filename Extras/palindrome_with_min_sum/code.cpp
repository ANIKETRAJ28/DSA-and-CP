//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
  int minimumSum(string s)
  {
    // code here
    int n = s.size();
    int i = 0, j = n - 1;
    int ans = 0;
    char last = '.';
    while (i <= j)
    {
      if (s[i] == '?' && s[j] == '?')
      {
        i++;
        j--;
        continue;
      }
      if (s[i] != '?' && s[j] != '?' && s[i] != s[j])
        return -1;
      char curr = s[i] == '?' ? s[j] : s[i];
      if (last != '.')
        ans += 2 * abs(last - curr);
      last = curr;
      i++;
      j--;
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;

    Solution ob;
    int ans = ob.minimumSum(s);
    cout << ans;
    cout << "\n";
  }
  return 0;
}

// } Driver Code Ends