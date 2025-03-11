//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// } Driver Code Ends

class Solution
{
public:
  vector<int> FirstNegativeInteger(vector<int> &arr, int k)
  {
    // write code here
    int n = arr.size();
    queue<int> qu;
    vector<int> ans;
    int i;
    for (i = 0; i < k; i++)
    {
      if (arr[i] < 0)
        qu.push(arr[i]);
    }
    if (qu.empty())
      qu.push(0);
    for (i; i < n; i++)
    {
      ans.push_back(qu.front());
      if (qu.front() == 0)
        qu.pop();
      else if (arr[i - k] < 0)
        qu.pop();
      if (arr[i] < 0)
        qu.push(arr[i]);
      if (qu.empty())
        qu.push(0);
    }
    ans.push_back(qu.front());
    return ans;
  }
};

//{ Driver Code Starts.
int main()
{
  string ts;
  getline(cin, ts);
  int t = stoi(ts);
  while (t--)
  {

    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number)
    {
      arr.push_back(number);
    }
    string ks;
    getline(cin, ks);
    int k = stoi(ks);
    Solution ob;
    vector<int> ans = ob.FirstNegativeInteger(arr, k);
    for (auto it : ans)
    {
      cout << it << " ";
    }
    cout << endl;
    cout << "~" << endl;
  }
  return 0;
}
// } Driver Code Ends