#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/range-sum-of-bst/

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  int rangeSumBST(TreeNode *root, int low, int high)
  {
    if (!root)
      return 0;
    int lft = rangeSumBST(root->left, low, high);
    int rgt = rangeSumBST(root->right, low, high);
    return (root->val >= low && root->val <= high) ? root->val + lft + rgt : lft + rgt;
  }
};

int main()
{

  return 0;
}