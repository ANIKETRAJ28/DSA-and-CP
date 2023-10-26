#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

class Solution
{
public:
    // Function to find minimum number of pages.
    int findPages(int A[], int N, int M)
    {
        if (M > N)
            return -1;
        int ans = -1;
        int lo = 0;
        int hi = 0;
        for (int i = 0; i < N; i++)
        {
            hi += A[i];
            lo = max(lo, A[i]);
        }
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int count = 1;
            int pages = 0;
            for (int i = 0; i < N; i++)
            {
                pages += A[i];
                if (pages > mid)
                {
                    count++;
                    pages = A[i];
                }
            }
            if (count <= M)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};

int main()
{

    return 0;
}