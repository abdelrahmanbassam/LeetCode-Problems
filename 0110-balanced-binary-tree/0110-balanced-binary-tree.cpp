/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool balanced = true;
    int depths(TreeNode* root){
        if(root == NULL)
            return 0;
        int leftDepth = 1 + depths(root->left);
        int rightDepth = 1 + depths(root->right);
        if(abs(leftDepth - rightDepth) > 1)
            balanced =false;
        return max(leftDepth,rightDepth);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        depths(root);
        return balanced;
    }
};