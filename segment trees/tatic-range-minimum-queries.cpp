#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://cses.fi/problemset/task/1647

void build(vector<ll> &tree, vector<ll> &arr, int i, int lo, int hi)
{
  if (lo == hi)
  {
    tree[i] = arr[lo];
    return;
  }
  int mid = lo + (hi - lo) / 2;
  build(tree, arr, 2 * i + 1, lo, mid);
  build(tree, arr, 2 * i + 2, mid + 1, hi);
  tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

ll find(vector<ll> &tree, vector<ll> &arr, int i, int l, int r, int L, int R)
{
  if (l > R || r < L)
    return INT_MAX;
  if (l >= L && r <= R)
    return tree[i];
  int m = l + (r - l) / 2;
  return min(find(tree, arr, 2 * i + 1, l, m, L, R), find(tree, arr, 2 * i + 2, m + 1, r, L, R));
}

int main()
{
  int n, q;
  cin >> n >> q;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  vector<ll> tree(4 * n);
  build(tree, arr, 0, 0, n - 1);
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    cout << find(tree, arr, 0, 0, n - 1, l - 1, r - 1) << "\n";
  }
  return 0;
}