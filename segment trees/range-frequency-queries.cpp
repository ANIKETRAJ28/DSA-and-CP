#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/range-frequency-queries/description/

class RangeFreqQuery
{
public:
  vector<unordered_map<int, int>> tree;
  int n;
  RangeFreqQuery(vector<int> &arr)
  {
    n = arr.size();
    tree.clear();
    tree.resize(4 * n);
    buildTree(arr, 0, 0, n - 1);
  }

  void buildTree(vector<int> &nums, int i, int lo, int hi)
  {
    if (lo == hi)
    {
      tree[i][nums[lo]]++;
      return;
    }
    int mid = lo + (hi - lo) / 2;
    buildTree(nums, 2 * i + 1, lo, mid);
    buildTree(nums, 2 * i + 2, mid + 1, hi);
    for (auto el : tree[2 * i + 1])
      tree[i][el.first] += el.second;
    for (auto el : tree[2 * i + 2])
      tree[i][el.first] += el.second;
  }

  int findFreq(int lo, int hi, int i, int &lRange, int &rRange, int &val)
  {
    if (lo > rRange || hi < lRange)
      return 0;
    if (lo >= lRange && hi <= rRange)
      return tree[i][val];
    int mid = lo + (hi - lo) / 2;
    int leftFreq = findFreq(lo, mid, 2 * i + 1, lRange, rRange, val);
    int rightFreq = findFreq(mid + 1, hi, 2 * i + 2, lRange, rRange, val);
    return leftFreq + rightFreq;
  }

  int query(int left, int right, int value)
  {
    return findFreq(0, n - 1, 0, left, right, value);
  }
};

int main()
{

  return 0;
}