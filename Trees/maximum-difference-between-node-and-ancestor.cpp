#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

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
  int ans = INT_MIN;
  vector<int> maxDiff(TreeNode *root)
  {
    int minEle = root->val;
    int maxEle = root->val;
    if (root->left)
    {
      vector<int> left = maxDiff(root->left);
      ans = max(ans, abs(root->val - left[0]));
      ans = max(ans, abs(root->val - left[1]));
      minEle = min(minEle, left[0]);
      maxEle = max(maxEle, left[1]);
    }
    if (root->right)
    {
      vector<int> right = maxDiff(root->right);
      ans = max(ans, abs(root->val - right[0]));
      ans = max(ans, abs(root->val - right[1]));
      minEle = min(minEle, right[0]);
      maxEle = max(maxEle, right[1]);
    }
    return {minEle, maxEle};
  }
  int maxAncestorDiff(TreeNode *root)
  {
    maxDiff(root);
    return ans;
  }
};

int main()
{

  return 0;
}