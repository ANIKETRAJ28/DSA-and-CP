//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
// } Driver Code Ends
class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int a[], int n, int x)
    {
        // Your Code Here
        sort(a, a + n);
        for (int i = 0; i < n - 2; i++)
        {
            int lo = i + 1, hi = n - 1;
            while (lo < hi)
            {
                if (a[i] + a[lo] + a[hi] == x)
                    return 1;
                else if (a[i] + a[lo] + a[hi] < x)
                    lo++;
                else
                    hi--;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends