#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://www.geeksforgeeks.org/problems/range-min-max-queries4557/1

class Solution
{
public:
  // Returns a vector<int> of size 2 where:
  // [0] = minimum value in arr from index L to R (inclusive),
  // [1] = maximum value in arr from index L to R (inclusive).
  // Uses the prebuilt segTree where each node stores [min, max].
  // Segment tree indexing:
  // - For a node at idx, left child is at 2*idx + 1, right child at 2*idx + 2.
  vector<int> miniMaxi(vector<int> &arr, int i, int lo, int hi, int L, int R, vector<vector<int>> &segTree)
  {
    if (lo > R || hi < L || lo > hi)
      return {INT_MAX, INT_MIN};
    if (lo >= L && hi <= R)
      return segTree[i];
    int mid = lo + (hi - lo) / 2;
    vector<int> left = miniMaxi(arr, 2 * i + 1, lo, mid, L, R, segTree);
    vector<int> right = miniMaxi(arr, 2 * i + 2, mid + 1, hi, L, R, segTree);
    int minVal = min(left[0], right[0]);
    int maxVal = max(left[1], right[1]);
    return {minVal, maxVal};
  }
  vector<int> getMinMax(vector<int> &arr, int L, int R, vector<vector<int>> &segTree)
  {
    // code here
    int n = arr.size();
    return miniMaxi(arr, 0, 0, n - 1, L, R, segTree);
  }
  // Updates the value at arr[index] to 'value' and updates the segTree accordingly.
  // Uses the prebuilt segTree where each node stores [min, max].
  // Segment tree indexing:
  // - For a node at idx, left child is at 2*idx + 1, right child at 2*idx + 2.
  void update(vector<int> &arr, int i, int index, int lo, int hi, int value, vector<vector<int>> &segTree)
  {
    if (lo == hi)
    {
      // arr[index] = value;
      segTree[i] = {value, value};
      return;
    }
    int mid = lo + (hi - lo) / 2;
    int minVal = segTree[i][0];
    int maxVal = segTree[i][1];
    if (index <= mid)
    {
      update(arr, 2 * i + 1, index, lo, mid, value, segTree);
    }
    else
    {
      update(arr, 2 * i + 2, index, mid + 1, hi, value, segTree);
    }
    minVal = min(segTree[2 * i + 1][0], segTree[2 * i + 2][0]);
    maxVal = max(segTree[2 * i + 1][1], segTree[2 * i + 2][1]);
    segTree[i] = {minVal, maxVal};
  }
  void updateValue(vector<int> &arr, int index, int value, vector<vector<int>> &segTree)
  {
    // code here
    int n = arr.size();
    update(arr, 0, index, 0, n - 1, value, segTree);
  }
};

int main()
{

  return 0;
}