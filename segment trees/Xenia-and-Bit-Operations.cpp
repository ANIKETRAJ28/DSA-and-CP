#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://codeforces.com/problemset/problem/339/D

void build(vector<ll> &arr, vector<ll> &tree, int i, int lo, int hi, int lvl)
{
  if (lo == hi)
  {
    tree[i] = arr[lo];
    return;
  }
  int mid = lo + (hi - lo) / 2;
  build(arr, tree, 2 * i + 1, lo, mid, lvl + 1);
  build(arr, tree, 2 * i + 2, mid + 1, hi, lvl + 1);
  if (lvl % 2)
  {
    tree[i] = tree[2 * i + 1] ^ tree[2 * i + 2];
  }
  else
  {
    tree[i] = tree[2 * i + 1] | tree[2 * i + 2];
  }
}

void update(vector<ll> &tree, int i, int lo, int hi, int idx, ll val, int lvl)
{
  if (lo == hi)
  {
    tree[i] = val;
    return;
  }
  int mid = lo + (hi - lo) / 2;
  if (idx <= mid)
  {
    update(tree, 2 * i + 1, lo, mid, idx, val, lvl + 1);
  }
  else
  {
    update(tree, 2 * i + 2, mid + 1, hi, idx, val, lvl + 1);
  }
  if (lvl % 2)
  {
    tree[i] = tree[2 * i + 1] ^ tree[2 * i + 2];
  }
  else
  {
    tree[i] = tree[2 * i + 1] | tree[2 * i + 2];
  }
}

int main()
{
  ll n, q;
  cin >> n >> q;
  ll ele = 1 << n;
  vector<ll> arr(ele);
  for (int i = 0; i < ele; i++)
  {
    cin >> arr[i];
  }
  vector<ll> tree(4 * ele);
  build(arr, tree, 0, 0, ele - 1, 1);
  while (q--)
  {
    int x;
    ll y;
    cin >> x >> y;
    update(tree, 0, 0, ele - 1, x - 1, y, 1);
    cout << tree[0] << "\n";
  }
  return 0;
}