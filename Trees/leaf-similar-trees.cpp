#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/leaf-similar-trees/

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
  void traverse(TreeNode *root, vector<int> &v)
  {
    if (!root->left && !root->right)
    {
      v.push_back(root->val);
      return;
    }
    if (root->left)
      traverse(root->left, v);
    if (root->right)
      traverse(root->right, v);
  }
  bool leafSimilar(TreeNode *root1, TreeNode *root2)
  {
    vector<int> v1, v2;
    traverse(root1, v1);
    traverse(root2, v2);
    if (v1.size() != v2.size())
      return false;
    int n = v1.size();
    for (int i = 0; i < n; i++)
    {
      if (v1[i] != v2[i])
        return false;
    }
    return true;
  }
};

int main()
{

  return 0;
}