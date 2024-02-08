#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/binary-tree-paths/submissions/

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
    vector<string> ans;
    void f(TreeNode* root, string s) {
        if(!root) return;
        if(!root->left and !root->right) {
            s +=  to_string(root->val);
            ans.push_back(s);
            return;
        }
        s +=  to_string(root->val);
        s += '-';
        s += '>';
        f(root->left,s);
        f(root->right,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        f(root, "");
        return ans;
    }
};

int main(){
    
    return 0;
}