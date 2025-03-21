//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
  template <class T>
  static void input(vector<T> &A, int n)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%d ", &A[i]);
    }
  }

  template <class T>
  static void print(vector<T> &A)
  {
    for (int i = 0; i < A.size(); i++)
    {
      cout << A[i] << " ";
    }
    cout << endl;
  }
};

// } Driver Code Ends

class Solution
{
public:
  int dp[1001][101][101];

  bool ftd(vector<int> &coins, int i, int target, int k, int n)
  {
    if (target == 0 && k == 0)
      return true;
    if (i == n || target == 0 || k == 0)
      return false;
    if (dp[target][i][k] != -1)
      return dp[target][i][k];
    bool notPick = ftd(coins, i + 1, target, k, n);
    bool pick = false;
    if (coins[i] <= target)
      pick = ftd(coins, i, target - coins[i], k - 1, n);
    return dp[target][i][k] = pick || notPick;
  }

  bool makeChanges(int N, int K, int target, vector<int> &coins)
  {
    // code here
    sort(coins.begin(), coins.end());
    memset(dp, -1, sizeof(dp));
    return ftd(coins, 0, target, K, N);
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  scanf("%d ", &t);
  while (t--)
  {

    int N;
    scanf("%d", &N);

    int K;
    scanf("%d", &K);

    int target;
    scanf("%d", &target);

    vector<int> coins(N);
    Array::input(coins, N);

    Solution obj;
    bool res = obj.makeChanges(N, K, target, coins);

    cout << res << endl;

    cout << "~" << "\n";
  }
}

// } Driver Code Ends