#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/evaluate-boolean-binary-tree/

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
  bool evaluateTree(TreeNode *root)
  {
    if (!root->left && !root->right)
      return root->val;
    bool lft = evaluateTree(root->left);
    bool rgt = evaluateTree(root->right);
    if (root->val == 2)
      return lft || rgt;
    if (root->val == 3)
      return lft && rgt;
    return root->val;
  }
};

int main()
{

  return 0;
}