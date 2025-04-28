#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    void preOrder(TreeNode *root, vector<int> &preVec)
    {
        if (!root)
            return;
        preVec.push_back(root->val);
        preOrder(root->left, preVec);
        preOrder(root->right, preVec);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preVec;
        preOrder(root, preVec);
        return preVec;
    }
};

class Solution
{
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        if (root)
            st.push(root);
        while (!st.empty())
        {
            TreeNode *temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if (temp->right)
                st.push(temp->right);
            if (temp->left)
                st.push(temp->left);
        }
        return ans;
    }
};

int main()
{

    return 0;
}