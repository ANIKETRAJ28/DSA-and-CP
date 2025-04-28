#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    void inOrder(TreeNode *root, vector<int> &inVec)
    {
        if (!root)
            return;
        inOrder(root->left, inVec);
        inVec.push_back(root->val);
        inOrder(root->right, inVec);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inVec;
        inOrder(root, inVec);
        return inVec;
    }
};

class Solution
{
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode *root)
    {
        TreeNode *node = root;
        stack<TreeNode *> st;
        while (node || !st.empty())
        {
            if (node)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                TreeNode *dummy = st.top();
                st.pop();
                ans.push_back(dummy->val);
                node = dummy->right;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}