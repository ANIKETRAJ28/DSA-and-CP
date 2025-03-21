//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  long long getCost(vector<pair<int, int>> &nums, int val)
  {
    int n = nums.size();
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
      ans += abs(nums[i].first - val) * nums[i].second;
    }
    return ans;
  }
  long long makeEqual(vector<int> &nums, vector<int> &cost)
  {
    // code here
    int n = nums.size();
    vector<pair<int, int>> temp(n);
    for (int i = 0; i < n; i++)
    {
      temp[i] = {nums[i], cost[i]};
    }
    sort(temp.begin(), temp.end());
    int lo = temp[0].first;
    int hi = temp[n - 1].first;
    long long ans = 0;
    while (lo < hi)
    {
      int mid = lo + (hi - lo) / 2;
      long long cost1 = getCost(temp, mid);
      long long cost2 = getCost(temp, mid + 1);
      ans = min(cost1, cost2);
      if (cost2 < cost1)
      {
        lo = mid + 1;
      }
      else
      {
        hi = mid;
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

void inputArray(vector<int> &arr)
{
  string line;
  getline(cin, line);
  stringstream ss(line);
  int num;
  while (ss >> num)
  {
    arr.push_back(num);
  }
}

int main()
{
  int t;
  cin >> t;
  cin.ignore();
  while (t--)
  {
    vector<int> arr, cost;
    inputArray(arr);
    inputArray(cost);
    Solution ob;
    long long res = ob.makeEqual(arr, cost);
    cout << res << endl;
  }
}
// } Driver Code Ends