#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        stack<pair<TreeNode *, int>> st;
        int ans = 0;
        if (root)
            st.push({root, 1});
        while (!st.empty())
        {
            auto el = st.top();
            st.pop();
            TreeNode *temp = el.first;
            int val = el.second;
            ans = max(ans, val);
            if (temp->left)
                st.push({temp->left, val + 1});
            if (temp->right)
                st.push({temp->right, val + 1});
        }
        return ans;
    }
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int ans = 0;
        queue<TreeNode *> qu;
        if (root)
            qu.push(root);
        while (!qu.empty())
        {
            ans++;
            int n = qu.size();
            while (n--)
            {
                TreeNode *temp = qu.front();
                qu.pop();
                if (temp->left)
                    qu.push(temp->left);
                if (temp->right)
                    qu.push(temp->right);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}