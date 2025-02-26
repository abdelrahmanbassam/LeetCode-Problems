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
    unordered_map<TreeNode*,int>depths;
    int getMaxDepths(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        depths[root] = max(getMaxDepths(root->left),getMaxDepths(root->right)) + 1;
        return depths[root];
    }
    int diameterOfBinaryTreeHelper(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftdepth = root->left == NULL ? 0 : depths[root->left];
        int rightdepth = root->right == NULL ? 0 : depths[root->right];

        return max(max(diameterOfBinaryTreeHelper(root->left),
                    diameterOfBinaryTreeHelper(root->right)),
                    leftdepth + rightdepth
                );
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getMaxDepths(root);
        return diameterOfBinaryTreeHelper(root);
    }
};