#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void postOrder(TreeNode *root, vector<int> &postVec) {
        if(!root) return;
        postOrder(root->left, postVec);
        postOrder(root->right, postVec);
        postVec.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postVec;
        postOrder(root, postVec);
        return postVec;
    }
};

int main() {
    
    return 0;
}