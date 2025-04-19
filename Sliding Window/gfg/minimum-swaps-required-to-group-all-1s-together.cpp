//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-group-all-1s-together2451/1

// } Driver Code Ends

class Solution
{
public:
  int minSwaps(vector<int> &arr)
  {
    int n = arr.size();
    int countone = 0;
    for (int i = 0; i < n; i++)
    {
      if (arr[i])
        countone++;
    }
    if (countone == 0)
      return -1;
    int minswap = INT_MAX;
    for (int i = 0; i < n - countone; i++)
    {
      int one = 0;
      for (int j = i; j < (i + countone); j++)
      {
        if (arr[j])
          one++;
      }
      minswap = min(minswap, (countone - one));
    }

    return minswap;
  }
  int minSwaps(vector<int> &arr)
  {
    // Complete the function
    int n = arr.size();
    int totalOnes = 0;
    for (int i = 0; i < n; i++)
    {
      if (arr[i])
        totalOnes++;
    }
    if (totalOnes == 0)
      return -1;
    int swaps = INT_MAX;
    int ones = 0;
    for (int i = 0; i < totalOnes; i++)
      if (arr[i])
        ones++;
    swaps = min(swaps, totalOnes - ones);
    int i = 0, j = totalOnes;
    while (j < n)
    {
      if (arr[i] == 1)
        ones--;
      if (arr[j] == 1)
        ones++;
      swaps = min(swaps, totalOnes - ones);
      j++;
      i++;
    }
    return swaps;
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
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> nums;
    int num;
    while (ss >> num)
    {
      nums.push_back(num);
    }
    Solution ob;
    cout << ob.minSwaps(nums) << endl;
  }
  return 0;
}

// } Driver Code Ends