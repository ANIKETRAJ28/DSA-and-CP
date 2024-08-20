#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(!root->left && !root->right) {
            if(val < root->val) root->left = new TreeNode(val);
            else root->right = new TreeNode(val);
            return root;
        }
        TreeNode *temp = root, *prnt = NULL;
        while(temp) {
            if(temp->left && val < temp->val) {
                temp = temp->left;
            }
            else if(temp->right && val > temp->val) {
                temp = temp->right;
            }
            else {
                prnt = temp;
                break;
            }
        }
        if(val < prnt->val) {
            TreeNode *dummy = prnt->left;
            prnt->left = new TreeNode(val);
            prnt->left->left = dummy;
        }
        else {
            TreeNode *dummy = prnt->right;
            prnt->right = new TreeNode(val);
            prnt->right->right = dummy;
        }
        return root;
    }
};

int main() {
    
    return 0;
}