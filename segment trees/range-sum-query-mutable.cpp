#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/range-sum-query-mutable/description/

class NumArray
{
public:
  vector<int> tree;
  int index, lRange, rRange, val, n;
  NumArray(vector<int> &nums)
  {
    n = nums.size();
    tree.resize(4 * n);
    buildTree(nums, 0, 0, n - 1);
  }

  void buildTree(vector<int> &nums, int i, int lo, int hi)
  {
    // base case
    if (lo == hi)
    {
      tree[i] = nums[lo];
      return;
    }
    int mid = lo + (hi - lo) / 2;
    // build left child
    buildTree(nums, 2 * i + 1, lo, mid);
    // build right child
    buildTree(nums, 2 * i + 2, mid + 1, hi);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
  }

  int getSum(int i, int lo, int hi)
  {
    // base case
    if (lRange > hi || rRange < lo)
      return 0;
    if (lo >= lRange && hi <= rRange)
      return tree[i];
    int mid = lo + (hi - lo) / 2;
    // left child sum
    int leftSum = getSum(2 * i + 1, lo, mid);
    // right child sum
    int rightSum = getSum(2 * i + 2, mid + 1, hi);
    return leftSum + rightSum;
  }

  void updateTree(int i, int lo, int hi)
  {
    if (lo == hi)
    {
      tree[i] = val;
      return;
    }
    int mid = lo + (hi - lo) / 2;
    if (index <= mid)
    {
      updateTree(2 * i + 1, lo, mid);
    }
    else
    {
      updateTree(2 * i + 2, mid + 1, hi);
    }
    // update current
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
  }

  void update(int index, int val)
  {
    this->index = index;
    this->val = val;
    updateTree(0, 0, n - 1);
  }

  int sumRange(int left, int right)
  {
    lRange = left;
    rRange = right;
    return getSum(0, 0, n - 1);
  }
};

int main()
{

  return 0;
}