#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/diameter-of-binary-tree/submissions/

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
    int Dia = 0;
    int f(TreeNode* root) {
        if(!root) return 0;
        int lDia = f(root->left);
        int rDia = f(root->right);
        return 1 + max(lDia, rDia);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        Dia = max(Dia, f(root->left) + f(root->right));
        Dia = max(Dia, diameterOfBinaryTree(root->left));
        Dia = max(Dia, diameterOfBinaryTree(root->right));
        return Dia;
    }
};

int main(){
    
    return 0;
}